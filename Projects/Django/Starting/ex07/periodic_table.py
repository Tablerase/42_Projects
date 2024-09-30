"""
Periodic Table: https://ptable.com/#Properties
"""

import sys

class Atom:
  def __init__(self, name, group, atomic_number, symbol, molar, electronic_config = None):
    self.name = name
    self.group = group
    self.atomic_number = atomic_number
    self.symbol = symbol
    self.molar = molar
    self.electronic_config = electronic_config if electronic_config else ""
  
  def __str__(self) -> str:
    return f"{self.symbol} ({self.atomic_number})"

  def __repr__(self) -> str:
    return f"⚛️ {self.name} ({self.symbol}):\n \
            - num: {self.atomic_number}\n \
            - group: {self.group}\n \
            - molar: {self.molar}\n \
            - electro: {self.electronic_config}\n"

def periodic_table() -> list[Atom] :
  """
  Create a list of Atoms from a file

  :return periodic_list: List of Atoms in the file
  """
  file_to_open = "periodic_table.txt"
  with open(file_to_open, "r") as file:
    content = file.read()
  
  # Parse content into a list of Atoms
  periodic_list = []
  for line in content.splitlines():
    line_element = line.strip().split(',')
    main_info = line_element[0].split('=')
    name = main_info[0].strip()
    group = main_info[1].split(':')[1].strip()
    number = line_element[1].split(':')[1].strip()
    symbol = line_element[2].split(':')[1].strip()
    molar = line_element[3].split(':')[1].strip()
    electronic_config = line_element[4].split(':')[1].strip()
    atom = Atom(
      name= name, 
      group= group,
      atomic_number= number,
      symbol= symbol,
      molar= molar,
      electronic_config= electronic_config
    )
    periodic_list.append(atom)
  return periodic_list

def make_html(periodic_list: list[Atom]):
  """
  Create the html file to display the periodic table

  :param periodic_list: List of Atom from the parsed file
  :type periodic_list: List[Atom]
  """

if __name__ == "__main__" :
  """
  Uses a file to write a HTML page representing the periodic
  table of the elements in a proper format.
  """
  try:
    periodic_list = periodic_table()
    make_html(periodic_list)

  except IndexError:
    sys.stdout.write("Invalid format in periodic input file\n")
    sys.stdout.flush()