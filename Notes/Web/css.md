# CSS (Cascade Style Sheet)

CSS is a language that describes the style of an HTML document. CSS describes how HTML elements should be displayed.

## CSS Syntax
```css
selector {
    property: value;
}
```

## CSS Selectors
* **Element Selector**: Selects all elements with the specified element name.
```css
p {
    color: red;
}
```

* **Class Selector**: Selects all elements with the specified class name.
```css
.class {
    color: red;
}
```

* **ID Selector**: Selects a single element with the specified id attribute.
```css
#id {
    color: red;
}
```

* **Universal Selector**: Selects all elements on the page.
```css
* {
    color: red;
}
```

* **Group Selector**: Selects all elements with the specified class name.
```css
h1, h2, h3 {
    color: red;
}
```

* **Descendant Selector**: Selects all elements that are descendants of a specified element.
```css
div p {
    color: red;
}
```

* **Child Selector**: Selects all elements that are direct children of a specified element.
```css
div > p {
    color: red;
}
```

* **Adjacent Sibling Selector**: Selects all elements that are the adjacent siblings of a specified element.
```css
h1 + p {
    color: red;
}
```

* **Attribute Selector**: Selects elements based on the presence or value of a specified attribute.
```css
a[target="_blank"] {
    color: red;
}
```

* **Pseudo-class Selector**: Selects elements based on a certain state or condition.
```css
a:hover {
    color: red;
}
```

* **Pseudo-element Selector**: Selects a specific part of an element.
```css
p::first-line {
    color: red;
}
```

## CSS variables

```css
:root {
    --light-color: #f8f9fa;
    --dark-color: #343a40;
}
```

## Colors

### Color Formats

* **Hexadecimal**: `#RRGGBB`
* **RGB(Red, Green, Blue)**: `rgb(255, 0, 0)`
* **RGBA**: `rgba(255, 0, 0, 0.5)`
* **HSL(Hue, Saturation, Lightness)**: `hsl(0, 100%, 50%)`
* **HSLA**: `hsla(0, 100%, 50%, 0.5)`
* **HWB(Hue, Whiteness, Blackness)**: `hwb(0, 0%, 0%)`
* **LAB(Lightness, a, b)**: `lab(53.24%, 80.09, 67.2)`
* **LCH(Lightness, Chroma, Hue)**: `lch(53.24%, 101.29, 40.85deg)`
* **Named Color**: `red`
* **...**

### [Light and Dark Mode](https://developer.mozilla.org/en-US/docs/Web/CSS/color_value/light-dark)

`light-dark()` is a CSS function that takes two colors as arguments and returns the first color if the user's system is in light mode and the second color if the user's system is in dark mode.

```css
p {
    color: light-dark(var(--light-color), var(--dark-color));
}