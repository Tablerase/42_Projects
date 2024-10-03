def get_color(color_symbol: str) -> str:
  """
  Find ANSI color for Specified symbol

  :param color_symbol: Symbol corresponding to wanted ANSI code
  :type color_symbol: str

  :return ANSI code: String code to enable terminal color,
  returns an empty str if symbol code not found
  """
  colors = {
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
    "RESET": "\033[0m"
  }
  return colors.get(color_symbol, "")

class HotBeverage:
    def __init__(self) -> None:
        self.name = "hot beverage"
        self.price = 0.30

    def description(self) -> str:
        return "Just some hot water in a cup."

    def __str__(self) -> str:
        blue = get_color("BLU") 
        yellow = get_color("YEL")
        magenta = get_color("MAG")
        reset = get_color("RESET")
        output = f"name: {blue}{self.name}{reset}\n" + f"price: {magenta}{self.price:.2f}{reset}\n" + f"description: {yellow}{self.description()}{reset}"
        return output

class Coffee(HotBeverage):
    def __init__(self) -> None:
        self.name = "coffee"
        self.price = 0.40
    def description(self) -> str:
        return "A coffee, to stay awake."

class Tea(HotBeverage):
    def __init__(self) -> None:
        self.name = "tea"
        self.price = 0.30
    def description(self) -> str:
        return "Just some hot water in a cup."

class Chocolate(HotBeverage):
    def __init__(self) -> None:
        self.name = "chocolate"
        self.price = 0.50
    def description(self) -> str:
        return "Chocolate, sweet chocolate..."

class Cappucino(HotBeverage):
    def __init__(self) -> None:
        self.name = "cappucino"
        self.price = 0.45
    def description(self) -> str:
        return "Un po' di Italia nella sua tazza!"

if __name__ == "__main__":
    """
    Tests
    """
    coco = HotBeverage()
    print(coco)
    coffee = Coffee()
    print(coffee)
    tea = Tea()
    print(tea)
    choco = Chocolate()
    print(choco)
    cappucino = Cappucino()
    print(cappucino)

