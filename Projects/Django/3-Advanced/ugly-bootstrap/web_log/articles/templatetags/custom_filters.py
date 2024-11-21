from django import template
from django.utils.timesince import timesince

register = template.Library()


@register.filter(name="get_attr")
def get_attr(obj, field_name):
    return getattr(obj, field_name, None)


@register.filter(name="time_since")
def time_since(value):
    return timesince(value)


@register.filter(name="truncate_str")
def truncate_str(value, max_lenght):
    if len(value) > max_lenght:
        return value[:max_lenght] + '...'
    return value
