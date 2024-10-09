"""
Periodic Table: https://ptable.com/#Properties
Element types: https://chem.libretexts.org/Bookshelves/General_Chemistry/Map%3A_Chemistry_-_The_Central_Science_(Brown_et_al.)/07%3A_Periodic_Properties_of_the_Elements/7.06%3A_Metals_Nonmetals_and_Metalloids
"""

import sys

class Atom:
  def __init__(self, 
               name : str, 
               group : int, 
               atomic_number : int, 
               symbol : str, 
               molar : float, 
               electronic_config : str
               ):
    self.name = name
    self.group = group
    self.atomic_number = atomic_number
    self.symbol = symbol
    self.molar = molar
    self.electronic_config = electronic_config if electronic_config else ""
  
  def __str__(self) -> str:
    return f"{self.symbol} ({self.atomic_number})"

  def __repr__(self) -> str:
    return f"{self.name} ({self.symbol}):\n \
            - num: {self.atomic_number}\n \
            - group: {self.group}\n \
            - molar: {self.molar}\n \
            - electro: {self.electronic_config}\n"

def get_type(atom_to_define : Atom) -> str:
  """
  Find the type of an atom Metal, Non-Methal or Metalloid

  :param atom_to_define: atom of which we want to find the type
  :type atom_to_define: Atom
  :return type: the type of the atom as a string
  """
  metals = ["Li", "Be", "Na", "Mg", "Al", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Cs", "Ba", "La", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "Fr", "Ra", "Ac", "Rf", "Db", "Sg", "Bh", "Hs"]
  non_metals = ["H", "He", "C", "N", "O", "F", "Ne", "P", "S", "Cl", "Ar", "Se", "Br", "Kr", "I", "Xe", "Rn"]
  metalloids = ["B", "Si", "Ge", "As", "Sb", "Te", "At"]

  if atom_to_define.symbol in metals:
    return "metals"
  elif atom_to_define.symbol in non_metals:
    return "non-metals"
  elif atom_to_define.symbol in metalloids:
    return "metalloids"
  else:
    return "unknown"

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
      group= int(group),
      atomic_number= int(number),
      symbol= symbol,
      molar= float(molar),
      electronic_config= electronic_config
    )
    periodic_list.append(atom)
  return periodic_list

def html_header() -> str :
  header = '''<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Periodic Table</title>
  <link rel="stylesheet" href="periodic_table.css">
</head>
<body>
'''
  return header

def html_footer() -> str:
  footer = '''
</body>
</html>
'''
  return footer

def html_body(periodic_list: list[Atom]) -> str:
  # Start of HTML Table
  body = '''
<h1>⚛️ Atoms are Awesome ⚛️</h1>
<table>
  <thead>
    <tr>
      <th colspan="1"></th>
      <th colspan="4" class="metals">Metals</th>
      <th colspan="4" class="metalloids">Metalloids</th>
      <th colspan="4" class="non-metals">Non Metals</th>
      <th colspan="4" class="unknown">Unknown</th>
      <th colspan="1"></th>
    </tr>
    <tr>
      <th colspan="18">Periodic Table</th>
    </tr>
  </thead>
  <tbody>
'''
  # Each row / periods
  atomic_index = 0
  for i in range(0, 6 + 1):
    body += '  <tr>\n'
    # Add each element from same period
    for j in range(0, 17 + 1):
      atom = periodic_list[atomic_index]
      if (atom.group == j) :
        body += f'''<td class="{get_type(atom)}">
  <h4>{atom.name}</h4>
  <ul class="atom-element">
    <li>{atom.atomic_number}</li>
    <li>{atom.symbol}</li>
    <li>{atom.molar}</li>
  </ul>
</td>
'''
        atomic_index += 1
      else :
        body += f'<td></td>'
  body += '  </tr>\n'

  # End of Table
  body += '  </tbody>\n\
</table>\n'
  return body

def make_html(periodic_list: list[Atom]):
  """
  Create the html file to display the periodic table

  :param periodic_list: List of Atom from the parsed file
  :type periodic_list: List[Atom]
  """
  content = html_header()
  content += html_body(periodic_list)
  content += html_footer()
  with open("periodic_table.html", "w") as file :
    file.write(content)

def make_css():
  """
  Create the css file for the periodic table html page
  """
  style = '''
* {
  box-sizing: border-box;
  font-family: Arial, sans-serif;
}

h1 {
  text-align: center;
  margin-bottom: 20px;
}

table {
  width: 100%;
  border-collapse: collapse;
  margin: auto;
  border-radius: 20px;
  overflow: hidden;
}

td {
  text-align: center;
  padding: 8px;
}

td:hover {
  border: 2px solid #f0f;
}

h4 {
  font-size: 0.9em;
}

.atom-element {
  list-style-type: none;
  font-size: 0.7em;
  padding: 0;
}

.metals {
  background-color: #ffcccb;
}

.non-metals {
  background-color: #ccffcc;
}

.metalloids {
  background-color: #ccccff;
}

.unknown {
  background-color: #dddddd;
}
'''
  with open("periodic_table.css", "w") as file:
      file.write(style)

if __name__ == "__main__" :
  """
  Uses a file to write a HTML page representing the periodic
  table of the elements in a proper format.
  """
  try:
    periodic_list = periodic_table()
    make_css()
    make_html(periodic_list)
  except IndexError:
    sys.stdout.write("Invalid format in periodic input file\n")
    sys.stdout.flush()