from elements import Html, Head, Meta, Title, Body, Div, H1, H2, P, Ul, Ol, Li, Table, Th, Tr, Td, Span, Img, Hr, Br, Elem
from elem import Text
from elements import ansi_color

class Page:
    def __init__(self, elem : Elem) -> None:
        self.content = elem
    
    def __str__(self) -> str:
        if isinstance(self.content, (Html)):
            result = '<!DOCTYPE html>\n'
            result += self.content.__str__()
            return result
        else:
            return self.content.__str__()
    
    def write_to_file(self, file_name: str) -> None:
        with open(file_name, "w") as file:
            file.write(self.content.__str__())

    def recurv_validation(self, elem) -> bool:
        # print(f"Source: {type(elem)}")
        # if (type(elem) != Text):
        #     for sub in elem.content:
        #         print(type(sub))

        # Allowed types
        if not isinstance(elem, (Html, Head, Meta, Title, 
                                 Div, Body, H1, H2, P, Ul, 
                                 Ol, Li, Table, Th, Tr, Td, 
                                 Span, Hr, Br, Img, Text)):
            return False
        # Base case
        if isinstance(elem, Text):
            return True
        # Html with head followed by body
        elif isinstance(elem, Html) and len(elem.content) == 2 \
            and isinstance(elem.content[0], Head) \
            and isinstance(elem.content[1], Body):
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        # Head only one Title
        elif isinstance(elem, Head) \
            and [isinstance(sub, Title) for sub in elem.content].count(True) == 1 :
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        # Titles and P only Text inside
        elif isinstance(elem, ( P, Title, H1, H2, Li, Th, Td )) \
            and len(elem.content) == 1 and type(elem.content[0]) == Text:
            return True
        # Span with only Text or P inside
        elif isinstance(elem, (Span)) \
            and len(elem.content) == 1 \
            and (type(elem.content[0]) == Text or type(elem.content[0]) == P):
            return True
        # Body/Div content 
        elif isinstance(elem, (Body, Div)) :
            if (all(isinstance(sub, (H1, H2, Div, Table, Ul, Ol, Span, Text)) for sub in elem.content)):
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        # Ol and Ul only contains li and at least one li
        elif isinstance(elem, (Ol, Ul)) :
            if (all(isinstance(sub, (Li)) for sub in elem.content)):
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        # Table only with tr
        elif isinstance(elem, (Table)):
            if (all(isinstance(sub, (Tr)) for sub in elem.content)):
                if (all(self.recurv_validation(sub) for sub in elem.content)):
                    return True
        # Tr only contains Td or Th (mutually exclusive)
        elif isinstance(elem, (Tr)):
            # mutually exclusive
            if len(elem.content) != 0 and isinstance(elem.content[0],(Td)):
                if (all(isinstance(sub, (Td)) for sub in elem.content)):
                    if (all(self.recurv_validation(sub) for sub in elem.content)):
                        return True
            elif len(elem.content) != 0 and isinstance(elem.content[0],(Th)):
                if (all(isinstance(sub, (Th)) for sub in elem.content)):
                    if (all(self.recurv_validation(sub) for sub in elem.content)):
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
        print(ansi_color("BLU") + f"{name_of_test}: ", end="")
        print(" ✅" + ansi_color("RESET"))
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
    test_print("Elem child class only", test, False)

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

def test_body():
    test = Page(
                Body([
                    Div(Text("Yo")),
                    Text("Lo")
                    ])
            )
    test_print("Body and Div contains only some types", test, True)
    test = Page(
                Body([
                    Div(Text("Yo")),
                    P(Text("Lo"))
                    ])
            )
    test_print("Body and Div with invalid types", test, False)

def test_span():
    test = Page(
                Span([
                    Text("Only Text"),
                ])
            )
    test_print("Span only with Text", test, True)
    test = Page(
                Span([
                    H1([Text("Invalid Text")]),
                ])
            )
    test_print("Span only with invalid Type", test, False)

def test_olul():
    test = Page(
                Div([
                    Ul([
                        Li([Text("One li")])
                    ]),
                    Ol([
                        Li([Text("One li")])
                    ])
                ])
            )
    test_print("Ul/Ol only with Li", test, True)
    test = Page(
                Div([
                    Ul([
                        Li([Text("One li")]),
                        Text("Error")
                    ]),
                    Ol([
                        Li([Text("One li")]),
                        Li([Text("...")])
                    ])
                ])
            )
    test_print("Ul/Ol only with invalid type", test, False)


def test_table():
    test = Page(
                Div([
                    Table([
                        Text("Error")
                    ])
                ])
    )
    test_print("Table without Tr", test, False)
    test = Page(
                Div([
                    Table([
                        Tr([
                            Td([
                                Text("One cell")
                            ])
                        ]),
                        Tr([
                            Td([
                                Text("One cell")
                            ])
                        ])
                    ])
                ])
            )
    test_print("Table with only Tr", test, True)
    test = Page(
                Div([
                    Table([
                        Li([
                            Text("Error")
                        ])
                    ])
                ])
            )
    test_print("Table with invalid Type", test, False)

def test_tr():
    test = Page(
            Div([
                Table([
                    Tr([
                        Li([
                            Text("error")
                        ])
                    ])
                ])
            ])
        )
    test_print("Tr with invalid type", test, False)
    test = Page(
                Div([
                    Table([
                        Tr([
                            Td([
                                Text("One cell")
                            ])
                        ]),
                        Tr([
                            Td([
                                Text("One cell")
                            ])
                        ])
                    ])
                ])
            )
    test_print("Tr with only Td", test, True)
    test = Page(
                Div([
                    Table([
                        Tr([
                            Th([
                                Text("One cell")
                            ]),
                            Th([
                                Text("another cell")
                            ])
                        ])
                    ])
                ])
            )
    test_print("Tr with only Th", test, True)
    test = Page(
                Div([
                    Table([
                        Tr([
                            Th([
                                Text("One cell")
                            ]),
                            Td([
                                Text("another cell")
                            ])
                        ])
                    ])
                ])
            )
    test_print("Tr without exclusivity for td, th", test, False)

def test_page():
    print(ansi_color("CYN") + "====================================" + ansi_color("RESET"))
    print(ansi_color("BLU") + "Print with html as root:" + ansi_color("RESET"))
    test = Page(
            Html([
                    Head([ 
                        Title( Text("Hello") ) 
                        ]),
                    Body([ 
                            Text("Hello") 
                        ])
                ])
            )
    print(test)
    print(ansi_color("BLU") + "Print without html as root:" + ansi_color("RESET"))
    test = Page(
                Div([
                    Table([
                        Tr([
                            Th([
                                Text("One cell")
                            ]),
                            Td([
                                Text("another cell")
                            ])
                        ])
                    ])
                ])
            )
    print(test)

def test_write():
    test = Page(    
                Html(
                    [
                        Head(Title(Text("Hello ground!"))),
                        Body([
                            H1(Text("Oh no, not again!")),
                            Img({"src":"http://i.imgur.com/pfp3T.jpg"})
                            ])
                    ]))
    print(ansi_color("CYN") + "====================================" + ansi_color("RESET"))
    try:
        test.write_to_file("HelloThere.html")
        print(ansi_color("BLU") + "File :" + ansi_color("RESET"))
        print(test)
    except Exception as e:
        print(e)


def tests():
    test_elem()
    test_html()
    test_title()
    test_body()
    test_span()
    test_olul()
    test_table()
    test_tr()

    test_page()
    test_write()
    
if __name__ == "__main__":
    tests()
