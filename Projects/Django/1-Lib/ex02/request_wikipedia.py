from re import search
import requests
import json
import dewiki #remove wiki markup text
import sys

"""
Program that takes a string as paramater and make search with wikipedia API 
    -> recover json data from API
    -> clean json and markup data
    -> writing result in a file
"""

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


def wiki_search(to_search : str):
    """
    Search Wikipedia API for a string and create a file with the result
    """
    wiki_endpoint = "https://fr.wikipedia.org/w/api.php"
    params = {
        "action": "parse",
        "page": to_search,
        "format": "json",
        "redirects": 1,
        "prop": "wikitext"
    }
    response = requests.get(url=wiki_endpoint, params=params)
    if response.status_code == 200:
        data = response.json()
        print(dewiki.from_string(data["parse"]["wikitext"]["*"]))
        # TODO: write to file and format file name
    else:
        Exception(f"Error: Failed to fetch data. Status code: {response.status_code}")


if __name__ == "__main__":
    # Simple Check paramater 
    if len(sys.argv) == 2 and len(sys.argv[1]) != 0 :
        try:
            wiki_search(sys.argv[1])
        except Exception as e :
            print(ansi("REDB") + str(e) + ansi("RESET"), file=sys.stderr)
    else:
        print(
            ansi("RED") + "Usage:\n"
            + ansi("YEL") + "python3 request_wikipedia.py <parameter_to_seach>"
            + ansi("RESET"), 
            file=sys.stderr
        )

