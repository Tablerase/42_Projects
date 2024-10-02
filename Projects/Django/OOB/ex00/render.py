import os
import re
import sys

# Recover values from 
import settings

def get_template() -> str:
  """
  Returns the content of the template file

  :raise ValueError: file extension is unsupported (only .template allowed)
  :raise Exception: invalid amount of arguments
  """
  if (len(sys.argv) != 2):
    raise Exception("Invalid nb of arguments: [Usage] python3 render.py CV.template")
  try:
    if (sys.argv[1].strip().rindex(".template") == len(sys.argv[1].strip()) - len(".template")):
      file_to_open = sys.argv[1].strip()
      with open(file_to_open, "r") as file:
        content = file.read()
      return content
  except ValueError:
    raise Exception(f"{sys.argv[1].strip()} file extension not supported")
      

def rendering(template : str):
  """
  Use template to generate a HTML page with fields replaced

  :param template: String that contains the data form .template file
  :type template: str
  """
  print(template)
  result = re.search(r'\{[\w]\}', template)
  print(result)

if __name__ == "__main__":
  try:
    content = get_template()
    rendering(content)
  except Exception as e:
    sys.stderr.write(f"{e}\n")
