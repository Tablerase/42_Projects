"""
Regex pattern : https://regex101.com/
"""

import os
import re
import sys

# Recover settings values
from settings import *

def get_template() -> str:
  """
  Returns the content of the template file

  :raise ValueError: file extension is unsupported (only .template allowed)
  :raise Exception: invalid amount of arguments
  """
  if (len(sys.argv) != 2):
    raise Exception("Invalid nb of arguments: \n\t[Usage] python3 render.py file.template")
  try:
    if (sys.argv[1].strip().rindex(".template") == len(sys.argv[1].strip()) - len(".template")):
      file_to_open = sys.argv[1].strip()
      with open(file_to_open, "r") as file:
        content = file.read()
      return content
  except ValueError:
    raise Exception(f"{sys.argv[1].strip()} file extension not supported")
  return ""

def rendering(template : str):
  """
  Use template to generate a HTML page with fields replaced

  :param template: String that contains the data form .template file
  :type template: str
  """
  # { : match char, () capture 1st group, \w+ matches any words character, } : match char
  pattern = r"{(\w+)}"
  # Find all matches
  matches = re.findall(pattern, template)
  # Replace each match with appropriate values
  for key in matches:
    if key in globals():
      template = re.sub(rf"{{{key}}}", globals()[key], template)
  
  # Create the html page
  file_to_create = sys.argv[1].strip().removesuffix(".template") + ".html"
  with open(file_to_create, "w") as file:
    file.write(template)

if __name__ == "__main__":
  try:
    content = get_template()
    rendering(content)
  except Exception as e:
    sys.stderr.write(f"{e}\n")
