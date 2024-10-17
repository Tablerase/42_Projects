from django.shortcuts import render

# Create your views here.

def color_shade(request):
    # Color list
    colors = ['Black', 'Red', 'Green', 'Blue']
    # Grid values
    shade = 2.5 # 255 / 50 shades / 2
    column_black = []
    column_red = []
    column_green = []
    column_blue = []
    color_value = 255
    for i in range(0, 50) :
        color_value = color_value - shade
        column_black.append(f'rgb({color_value},{color_value},{color_value})')
        column_red.append(f'rgb({color_value},0,0)')
        column_green.append(f'rgb(0,{color_value},0)')
        column_blue.append(f'rgb(0,0,{color_value})')
    shades_of_colors = {
            colors[0] : column_black,
            colors[1] : column_red,
            colors[2] : column_green,
            colors[3] : column_blue,
    }
    # Context
    context = {
            'active_page': 'color_shade',
            'colors': colors,
            'shades_of_colors' : shades_of_colors,
            'range' : range(50),
    }
    return render(request, 'color_shade.html', context)

