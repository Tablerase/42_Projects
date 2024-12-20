"""
Program that create a road from wiki origine page to wiki page of philosophy
    -> request wiki page for search value (API not allowed)
        -> scrape first valid link -> request new page
        -> repeat process till philosophy page reached
    -> Give road taken
    -> Lenght of road from origine to destination

    -> display errors in case of loop or dead end and other possible errors 

>>> python3 roads_to_philosophy.py "L'albatros (poem)"
--> L'albatros (poem)
--> French language
--> Romance languages
--> Language
--> Communication
--> Information
--> Abstraction
--> Rule of inference
--> Logic
--> Logical reasoning
--> Action (philosophy)
--> Philosophy
12 roads form L'albatros (poem) to Philosophy
"""

import sys
import requests
# BeautifulSoup 4 - Parser / Scraper
from bs4 import BeautifulSoup, Tag

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

class Page:
    def __init__(self, input_title : str, input_link : str) -> None:
        self.title = input_title
        self.link = input_link
    def __str__(self) -> str:
        return self.title

def find_p(content):
    # Remove empty p tags that are direct children of content
    for p in content.find_all('p', class_='mw-empty-elt'):
        p.decompose()
    
    # Find the first non-empty p tag that is a direct child of content
    p = next((child for child in content.children if isinstance(child, Tag) and child.name == 'p'), None)
    
    return p

def find_a(content, history : list[Page]):
    for a in content.children:
        # Only <a> at child level
        if isinstance(a, Tag) and a.name  == 'a':
            href = a.get('href')
            # article page and skip page balise and wiki help
            if (href and href.startswith('/wiki/') and 
                href not in ['#', '/'] and
                not href.startswith('/wiki/Help:') ):
                for page in history:
                    if href == page.link:
                       # raise ValueError(f"Loop found at {href} in page {history[len(history) - 1].link}")
                       raise ValueError("It leads to an infinite loop !")
                return a
    return None

def step(history : list[Page], link : str) -> list[Page] :
    """
    Find in link page, first paragraph with valid link 
    to the next page until philosophy or dead end or loop

    Args:
        history (list[Page]): List of page reached at current iteration 11:47
        link (str): Link of page to searched

    Returns:
        history (list[Page]): history with next page as last entry
    """

    wikipedia = "https://en.wikipedia.org"
    # Find origine page
    response = requests.get(wikipedia + link)
    if response.status_code == 200 or response.status_code == 208:
        # Add origine to history
        soup = BeautifulSoup(response.content, 'html.parser')
        if len(history) == 0 :
            title = link.removeprefix('/wiki/')
            page = Page(title.replace('_', ' '), link)
            history.append(page)

        # Scrap for first link
        content = soup.find('div', class_='mw-content-ltr')
        if not content:
            # raise ValueError(f"No valid content found for page {link}")
            raise ValueError("It leads to a dead end !")
        first_paragraph = find_p(content)
        if not first_paragraph:
            raise ValueError("It leads to a dead end !")
        first_valid_link = find_a(first_paragraph, history)
        if not first_valid_link:
            # raise ValueError(f"No valid link found: \n {first_valid_link}\n in page {link}")
            raise ValueError("It leads to a dead end !")
        link = first_valid_link.get('href') 
        if not link:
            # raise ValueError(f"No valid elem link found:\n {first_valid_link}\n in page {link}")
            raise ValueError("It leads to a dead end !")
        title = first_valid_link.get('title')
        if not title:
            # raise ValueError(f"No valid title found from:\n {first_valid_link}\n in page {link}")
            raise ValueError("It leads to a dead end !")
        page = Page(title.replace('_', ' '), link)
        history.append(page)
    else:
        # raise Exception(f"Error: Failed to fetch data at {wikipedia}{link} | Status code: {response.status_code}")
        raise ValueError("It leads to a dead end !")

    return history


def roads_to_philosophy(origine_title : str):
    """
    Display amount of first valid links taken to reached philosophy wikipage
    """
    history = step([], '/wiki/' + origine_title.strip().replace(' ', '_'))
    print(ansi("CYN") + "--> " + ansi("YEL") 
          + history[0].title 
          + ansi("RESET"))
    while history[len(history) - 1].link != '/wiki/Philosophy':
        print(ansi("CYN") + "--> " + ansi("MAG") 
              + history[len(history) - 1].title 
              + ansi("RESET"))
        history = step(history, history[len(history) - 1].link)
    print(ansi("CYN") + "--> " + ansi("BLU") 
              + history[len(history) - 1].title 
              + ansi("RESET"))
    # Display final result:
    print(
        f"{len(history)} roads form {ansi('YEL')}{history[0]}{ansi('RESET')}"
        + f" to {ansi('BLU')}{history[len(history) - 1]}{ansi('RESET')}"
    )
    
if __name__ == "__main__":
    if len(sys.argv) == 2 and len(sys.argv[1]) != 0 :
        try:
            roads_to_philosophy(sys.argv[1])
        except ValueError as v :
            print(ansi("CYNB") + str(v) + ansi("RESET"))
        except Exception as e :
            print(ansi("REDB") + str(e) + ansi("RESET"), file=sys.stderr)
    else:
        print(
            ansi("RED") + "Usage:\n"
            + ansi("YEL") + "python3 roads_to_philosophy.py <origine_title>\n"
            + ansi("BLU") + 'py roads_to_philosophy.py "Car"\n'
            + ansi("BLU") + 'py roads_to_philosophy.py "Baudelaire"'
            + ansi("RESET"), 
            file=sys.stderr
        )
