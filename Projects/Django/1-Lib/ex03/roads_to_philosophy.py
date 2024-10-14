"""
Program that create a road from wiki origine page to wiki page of philosophy
    -> request wiki page for search value (API not allowed)
        -> scrape first valid link -> request new page
        -> repeat process till philosophy page reached
    -> Give road taken
    -> Lenght of road from origine to destination

    -> display errors in case of loop or dead end and other possible errors 
"""

import sys
import requests
from bs4 import BeautifulSoup

def ansi(color_symbol: str) -> str:
  """
  Find ANSI color for Specified symbol

  Args:
    code_symbol (str): Symbol corresponding to wanted ANSI code

  Returns:
    ANSI_code: String code to enable terminal font color, weight, returns an empty str if symbol code not found
  
  Examples:
    >>> print(ansi("RED") + Text_to_style + ansi("RESET))
  """
  code = {
    "BLK": "\033[0;30m",
    "RED": "\033[0;31m",
    "GRN": "\033[0;32m",
    "YEL": "\033[0;33m",
    "BLU": "\033[0;34m",
    "MAG": "\033[0;35m",
    "CYN": "\033[0;36m",
    "WHT": "\033[0;37m",
    "BBLK": "\033[1;30m",
    "BRED": "\033[1;31m",
    "BGRN": "\033[1;32m",
    "BYEL": "\033[1;33m",
    "BBLU": "\033[1;34m",
    "BMAG": "\033[1;35m",
    "BCYN": "\033[1;36m",
    "BWHT": "\033[1;37m",
    "UBLK": "\033[4;30m",
    "URED": "\033[4;31m",
    "UGRN": "\033[4;32m",
    "UYEL": "\033[4;33m",
    "UBLU": "\033[4;34m",
    "UMAG": "\033[4;35m",
    "UCYN": "\033[4;36m",
    "UWHT": "\033[4;37m",
    "BLKB": "\033[40m",
    "REDB": "\033[41m",
    "GRNB": "\033[42m",
    "YELB": "\033[43m",
    "BLUB": "\033[44m",
    "MAGB": "\033[45m",
    "CYNB": "\033[46m",
    "WHTB": "\033[47m",
    "GRAYB": "\033[100m",
    "BLKHB": "\033[0;100m",
    "REDHB": "\033[0;101m",
    "GRNHB": "\033[0;102m",
    "YELHB": "\033[0;103m",
    "BLUHB": "\033[0;104m",
    "MAGHB": "\033[0;105m",
    "CYNHB": "\033[0;106m",
    "WHTHB": "\033[0;107m",
    "HBLK": "\033[0;90m",
    "HRED": "\033[0;91m",
    "HGRN": "\033[0;92m",
    "HYEL": "\033[0;93m",
    "HBLU": "\033[0;94m",
    "HMAG": "\033[0;95m",
    "HCYN": "\033[0;96m",
    "HWHT": "\033[0;97m",
    "BHBLK": "\033[1;90m",
    "BHRED": "\033[1;91m",
    "BHGRN": "\033[1;92m",
    "BHYEL": "\033[1;93m",
    "BHBLU": "\033[1;94m",
    "BHMAG": "\033[1;95m",
    "BHCYN": "\033[1;96m",
    "BHWHT": "\033[1;97m",
    "ITALIC": "\033[3m",
    "RESET": "\033[0m"
  }
  return code.get(color_symbol, "")

def snake_case(str_to_snake : str) -> str :
    return str_to_snake.replace(' ', '_')

class Page:
    def __init__(self, input_title : str, input_link : str) -> None:
        self.title = snake_case(input_title)
        self.link = input_link
    def __str__(self) -> str:
        return self.title

def find_p(content):
    # Remove empty p
    for p in content.find_all('p', class_='mw-empty-elt'):
        p.decompose()
    p = content.find_next('p')
    return p 

def step(history : list[Page], link : str) -> list[Page] :
    wikipedia = "https://en.wikipedia.org"
    # Find origine page
    response = requests.get(wikipedia + link)
    if response.status_code == 200:
        # Add origine to history
        soup = BeautifulSoup(response.content, 'html.parser')
        if len(history) == 0 :
            title = link.removeprefix('/wiki/')
            page = Page(title.replace('_', ' '), link)
            history.append(page)

        # Scrap for first link
        content = soup.find('div', class_='mw-content-ltr')
        if not content:
            raise ValueError(f"No valid content found for page {link}")
        first_paragraph = find_p(content)
        first_valid_link = first_paragraph.find_next('a')
        if not first_valid_link:
            raise ValueError(f"No valid link found in page {link}")
        title = first_valid_link['title']
        if not title:
            raise ValueError(f"No valid title found in page {link}")
        link = first_valid_link['href'] 
        page = Page(title.replace('_', ' '), link)
        history.append(page)
    else:
        raise Exception(f"Error: Failed to fetch data. Status code: {response.status_code}")

    return history


def roads_to_philosophy(origine_title : str):
    """
    Display amount of first valid links taken to reached philosophy wikipage
    """
    history = step([], '/wiki/' + snake_case(origine_title))
    print(ansi("CYN") + "--> " + ansi("MAG") 
          + history[len(history) - 1].title 
          + ansi("RESET"))
    while history[len(history) - 1].title.lower() != 'philosophy':
        history = step(history, history[len(history) - 1].link)
        print(ansi("CYN") + "--> " + ansi("MAG") 
              + history[len(history) - 1].title 
              + ansi("RESET"))
    # Display final result:
    print(
        f"{len(history)} roads form {ansi('YEL')}{history[0]}{ansi('RESET')}"
        + f" to {ansi('BLU')}{history[len(history) - 1]}{ansi('RESET')}"
    )
    
if __name__ == "__main__":
    if len(sys.argv) == 2 and len(sys.argv[1]) != 0 :
        # try:
            roads_to_philosophy(sys.argv[1])
        # except Exception as e :
            # print(ansi("REDB") + str(e) + ansi("RESET"), file=sys.stderr)
    else:
        print(
            ansi("RED") + "Usage:\n"
            + ansi("YEL") + "python3 roads_to_philosophy.py <origine_title>"
            + ansi("RESET"), 
            file=sys.stderr
        )
