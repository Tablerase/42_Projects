from elem import Elem

def ansi_color(color_symbol: str) -> str:
  """
  Find ANSI color for Specified symbol

  Args:
    color_symbol (str): Symbol corresponding to wanted ANSI code

  Returns:
    ANSI_code: String code to enable terminal color, returns an empty str if symbol code not found
  
  Examples:
    >>> print(ansi_color("RED") + Text_to_color + ansi_color("RESET))
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


class Html(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('html', attr, content, tag_type='double')

class Body(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('body', attr, content, tag_type='double')

class Head(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('head', attr, content, tag_type='double')

# https://www.w3schools.com/tags/tag_title.asp
class Title(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('title', attr, content, tag_type='double')

# https://www.w3schools.com/tags/tag_meta.asp
class Meta(Elem):
    def __init__(self, attr={}):
        super().__init__('meta', attr, tag_type='simple')

# https://www.w3schools.com/tags/tag_img.asp
class Img(Elem):
    def __init__(self, attr={}):
        super().__init__('img', attr, tag_type='simple')

# https://www.w3schools.com/tags/tag_table.asp
class Table(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('table', attr, content, tag_type='double')

class Th(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('th', attr, content, tag_type='double')

class Tr(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('tr', attr, content, tag_type='double')

class Td(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('td', attr, content, tag_type='double')

class Ul(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('ul', attr, content, tag_type='double')

class Ol(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('ol', attr, content, tag_type='double')

class Li(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('li', attr, content, tag_type='double')

class H1(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('h1', attr, content, tag_type='double')

class H2(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('h2', attr, content, tag_type='double')

class P(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('p', attr, content, tag_type='double')

class Div(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('div', attr, content, tag_type='double')

# Inline Container
class Span(Elem):
    def __init__(self, content=None, attr={}):
        super().__init__('span', attr, content, tag_type='double')
    # Overides for inline content
    def __str__(self):
        result = f"<{self.tag}{self._Elem__make_attr()}"
        result += f">{self.__make_content()}</{self.tag}>"
        return result
    def __make_content(self):
        if len(self.content) == 0:
            return ''
        result = ''
        for elem in self.content:
          # edit section
            if len(str(elem)) != 0:
              result += f"{elem}" 
        if len(result.strip()) == 0:
          return ''
        #
        return result


# https://www.w3schools.com/tags/tag_hr.asp (hr = horizontal rule)
class Hr(Elem):
    def __init__(self, attr={}):
        super().__init__('hr', attr, tag_type='simple')

class Br(Elem):
    def __init__(self, attr={}):
        super().__init__('br', attr, tag_type='simple')

if __name__ == "__main__":
    try:
        print("======={TEST}=======")
        print(Html([Head(), Body()]))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Title("HelloThere"))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Meta({"charset": "UTF-8"}))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Img({"src": "https://i.imgur.com/nV8CfVg.jpeg"}))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Table([Th(Td("Header Value")), Tr(Td("Cell Value"))]))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Div(P(f"HelloYou { Span('Yolo', {'style':'color:blue'}) } HelloYou")))
        print(ansi_color("CYN") + "---------------" + ansi_color("RESET"))
        print(Div([P(["SomeTopic", Hr(), "Thematic change", Br(), "New Topic"])]))
        print(ansi_color("MAG") +
              "======={Previous Version made Easier}======="
              + ansi_color("RESET"))
        # body = Elem(tag='body')
        # h1 = Elem(tag='h1', content='"Oh no, <not again!"')
        # img = Elem(tag='img', attr={"src":"http://i.imgur.com/pfp3T.jpg"}, tag_type='simple')
        # body.add_content([h1, img])
        # head = Elem(tag='head')
        # title = Elem(tag='title', content='"Hello ground!"')
        # head.add_content(title)
        # html = Elem(tag='html')
        # html.add_content([head, body])
        print(Html([Head(Title("Hello ground!")),
                    Body([H1("Oh no, not again!"),
                          Img({"src":"http://i.imgur.com/pfp3T.jpg"})])
                    ]))
    except Exception as e:
        print(e)
