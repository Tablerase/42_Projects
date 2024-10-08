from elements import Html, Head, Meta, Title, Body, Div, H1, H2, P, Ul, Ol, Li, Table, Th, Tr, Td, Span, Img, Hr, Br, Elem
from elem import Text
from elements import ansi_color

class Page:
    def __init__(self, elem : Elem) -> None:
        self.content = elem

    def recurv_validation(self, elem) -> bool:
        print(f"Source: {type(elem)}")
        for sub in elem.content:
            print(type(sub))

        if not isinstance(elem, (Html, Head, Meta, Title, 
                                 Div, Body, H1, H2, P, Ul, 
                                 Ol, Li, Table, Th, Tr, Td, 
                                 Span, Hr, Br, Img, Text)):
            return False
        if isinstance(elem, Text):
            return True
        elif isinstance(elem, Html) and len(elem.content) == 2 \
            and isinstance(elem.content[0], Head) \
            and isinstance(elem.content[1], Body):
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        elif isinstance(elem, Head) \
            and [isinstance(sub, Title) for sub in elem.content].count(True) == 1 :
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        elif isinstance(elem, (Title, H1, H2, Li, Th, Td)) \
            and len(elem.content) == 1 and type(elem.content[0]) == Text:
            return True
        return False

    def isvalid(self) -> bool:
        if self.recurv_validation(self.content) == False:
            return False
        else:
            return True

def test_print(name_of_test: str, to_test : Page, expected : bool):
    try:
        assert to_test.isvalid() == expected
        print(f"{name_of_test}: ", end="")
        print(ansi_color("GRN") + " ✅" + ansi_color("RESET"))
    except AssertionError:
        print(f"{name_of_test}: ", end="")
        print(ansi_color("BRED") + "Fail" + ansi_color("RESET") )
    except Exception as e:
        print(ansi_color("REDB") + str(e) + ansi_color("RESET"))

def test_html():
    test = Page(
                Html([ \
                        Head([ 
                            Title( Text("Hello") ) 
                              ]), \
                        Body([ 
                             Text("Hello") 
                              ]) \
                    ]) \
                )
    test_print("html block head then body", test, True)
    test = Page(Html([Body(), Head()]))
    test_print("html block invalid order", test, False)

def test_elem():
    test = Page(Elem())
    test_print("ONLY Elem child class", test, False)

def test_title():
    test = Page( 
                Head([ \
                    Title([ \
                        Text("Hello") \
                        ])\
                    ])\
                )
    test_print("One title in head", test, True)
    test = Page( Head([ Title(), Title()]) )
    test_print("Too many title in head", test, False) 

def test():
    test_elem()
    test_html()
    test_title()
    
if __name__ == "__main__":
    test()
