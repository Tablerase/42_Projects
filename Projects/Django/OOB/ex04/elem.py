#!/usr/bin/python3


class Text(str):
    """
    A Text class to represent a text you could use with your HTML elements.

    Because directly using str class was too mainstream.
    """

    def __str__(self):
        """
        Do you really need a comment to understand this method?..
        """
        return super().__str__().replace('\n', '\n<br />\n')


class Elem:
    """
    Elem will permit us to represent our HTML elements.
    """
    # Edit section
    class ValidationError(Exception):
        def __init__(self):
            super().__init__("Invalid type")

    #

    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        """
        __init__() method.

        Obviously.
        """
        # Attributes section
        self.tag = tag
        self.tag_type = tag_type
        self.attr = attr
        self.content = content if content is not None else []
        ## !todo replacing <, >, " escape code for html compatibility
        self.content.__str__().replace('<', '&lt;')
        self.content.__str__().replace('>', '&gt;')
        self.content.__str__().replace('"', '&quot;')
        #

    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """
        result = f"<{self.tag}"
        if self.tag_type == 'double':
            # double pair tag : <p> </p>, <h1> </h1>, ...
            result += self.__make_attr()
            result += ">"
            result += self.__make_content()
            result += f"\n</{self.tag}>"
            #
        elif self.tag_type == 'simple':
            # single tag : <img>, <br>
            result += self.__make_attr()
            result += self.__make_content()
            result += "/>"
            #
        return result

    def __make_attr(self):
        """
        Here is a function to render our elements attributes.
        """
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def __make_content(self):
        """
        Here is a method to render the content, including embedded elements.
        """

        if len(self.content) == 0:
            return ''
        result = '\n'
        for elem in self.content:
            # edit inline from =
            result += Text(elem)
            #
        return result

    def add_content(self, content):
        if not Elem.check_type(content):
            raise Elem.ValidationError
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    @staticmethod
    def check_type(content):
        """
        Is this object a HTML-compatible Text instance or a Elem, or even a
        list of both?
        """
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))


if __name__ == '__main__':
    # Edit section
    test = Text('<')
    print(test)
    # try:
    # body = Elem(tag='body')
    # h1 = Elem(tag='h1', content='"Oh no, <not again!"')
    # img = Elem(tag='img', attr={"src":"http://i.imgur.com/pfp3T.jpg"}, tag_type='simple')
    # body.add_content([h1, img])
    # head = Elem(tag='head')
    # title = Elem(tag='title', content='"Hello ground!"')
    # head.add_content(title)
    # html = Elem(tag='html')
    # html.add_content([head, body])
    # print(html)
    # except Exception as e:
        # print(e)

    #
