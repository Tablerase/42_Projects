from path import Path
# Wrapper specifize in file management of os module 
# https://path.readthedocs.io/en/latest/api.html#path.Path

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

def the_function():
    try:
      # Create a folder
      ## https://docs.python.org/3/library/os.html#os.mkdir
      Path.mkdir("Baudelaire")

      # Create a file
      ## https://path.readthedocs.io/en/latest/api.html#path.Path.touch
      # Path.cd("Welcome")
      Path.touch("Baudelaire/Albatros")
      file = Path("Baudelaire/Albatros")

      text_to_write = """
  Souvent, pour s’amuser, les hommes d’équipage
  Prennent des albatros, vastes oiseaux des mers,
  Qui suivent, indolents compagnons de voyage,
  Le navire glissant sur les gouffres amers.

  A peine les ont-ils déposés sur les planches,
  Que ces rois de l’azur, maladroits et honteux,
  Laissent piteusement leurs grandes ailes blanches
  Comme des avirons traîner à côté d’eux.

  Ce voyageur ailé, comme il est gauche et veule !
  Lui, naguère si beau, qu’il est comique et laid !
  L’un agace son bec avec un brûle-gueule,
  L’autre mime, en boitant, l’infirme qui volait !

  Le Poète est semblable au prince des nuées
  Qui hante la tempête et se rit de l’archer ;
  Exilé sur le sol au milieu des huées,
  Ses ailes de géant l’empêchent de marcher.

  Charles Baudelaire
  """
      # Write in the file
      ## https://path.readthedocs.io/en/latest/api.html#path.Path.write_text
      file.write_text(text_to_write)

      # Read the file
      ## https://path.readthedocs.io/en/latest/api.html#path.Path.read_text
      text_read = file.read_text()

      # Display content
      blue = ansi("BLU")
      reset = ansi("RESET")
      italic = ansi("ITALIC")
      print(blue + "File content: \n" + reset + italic + text_read + reset)

    except Exception as e:
       print(ansi("REDB") + str(e) + ansi("RESET"))

if __name__ == '__main__':
    the_function()
