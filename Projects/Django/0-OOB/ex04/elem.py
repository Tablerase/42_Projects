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
        result = super().__str__()
        result = result.replace('>', '&gt;')
        result = result.replace('<', '&lt;')
        result = result.replace('"', '&quot;')
        result = result.replace('\n', '\n<br />\n')
        return result


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
        if tag_type != 'double' and tag_type != 'simple':
          raise self.ValidationError
        self.tag = tag
        self.tag_type = tag_type
        self.attr = attr
        self.content = []
        if not self.check_type(content) and len(str(content)) == 0:
          raise self.ValidationError
        elif isinstance(content, list) :
          self.content = content
        elif content is not None:
          self.content.append(content)

    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """

        result = f"<{self.tag}{self.__make_attr()}"
        if self.tag_type == 'double':
          # double pair tag : <p> </p>, <h1> </h1>, ...
          result += f">{self.__make_content()}</{self.tag}>"
          #
        elif self.tag_type == 'simple':
          # single tag : <img>, <br>
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
          # edit section
            if len(str(elem)) != 0:
              result += f"{elem}" + "\n"
        result = "  ".join(line for line in result.splitlines(True))
        if len(result.strip()) == 0:
          return ''
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
    try:
      body = Elem(tag='body')
      h1 = Elem(tag='h1', content='"Oh no, not again!"')
      img = Elem(tag='img', attr={"src":"http://i.imgur.com/pfp3T.jpg"}, tag_type='simple')
      body.add_content([h1, img])
      head = Elem(tag='head')
      title = Elem(tag='title', content='"Hello ground!"')
      head.add_content(title)
      html = Elem(tag='html')
      html.add_content([head, body])
      print(html)
    except Exception as e:
        print(e)

    #
