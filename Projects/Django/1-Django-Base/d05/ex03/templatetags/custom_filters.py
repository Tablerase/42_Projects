from django import template

register = template.Library()

@register.filter(name="get_item")
def get_item(dictionary, key):
    """
    Custom template filter to get a value from a dictionary using a key
    """
    return dictionary.get(key)

@register.filter(name="get_index")
def get_index(list_obj, index):
    """
    Custom template filter to get an item from a list using an index
    """
    try:
        return list_obj[index]
    except (IndexError, TypeError):
        return None  # Return None if the index is invalid
