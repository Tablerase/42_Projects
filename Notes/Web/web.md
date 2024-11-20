# Web

## URL

URL stands for Uniform Resource Locator. It is the address of a resource on the internet. It is a reference to a web resource that specifies its location on a computer network and a mechanism for retrieving it.

### Parts of a URL

A URL is composed of several parts:
- **Scheme**: The protocol used to access the resource, such as HTTP, HTTPS, FTP, etc.
- **Host**: The domain name or IP address of the server hosting the resource.
- **Port**: The port number to connect to the server.
- **Path**: The location of the resource in the server's file system.
- **Query**: Additional parameters for the resource.
- **Fragment**: A specific section of the resource.

#### Example

The following is an example of a URL:

```
https://www.example.com:8080/path/to/resource?param1=value1&param2=value2#section
```

- **Scheme**: `https`
- **Host**: `www.example.com`
- **Port**: `8080`
- **Path**: `/path/to/resource`
- **Query**: `param1=value1&param2=value2`
- **Fragment**: `section`

### [Slugs](https://webflow.com/glossary/slug)

A slug is a part of a URL that identifies a particular page on a website in a human-readable form. It is usually derived from the title of the page and is used to improve the SEO of the page.

#### Example

No slugs are present in the URL `https://www.example.com/blog/12345`. The URL is not human-readable and does not provide any information about the content of the page.
With a slug, the URL becomes `https://www.example.com/blog/my-first-post`. The slug `my-first-post` gives a clear indication of the content of the page.

## Script Placement in HTML

When adding JavaScript to a web page, the placement of the `<script>` tag can affect the page's performance and behavior. Here are some common placement options and best practices for adding scripts to HTML documents.

🖋️ [Explainthis - Script in html](https://www.explainthis.io/en/swe/script-link-in-html)

### Placement Options

#### At the bottom of the `<body>` tag:
```html
<body>
  <!-- All other content -->
  <script src="script.js"></script>
</body>
```
**Key points:**
- Allows page content to render first before scripts load
- Avoids potential errors from trying to modify elements that haven't loaded yet

#### In the `<head>` tag with `defer` attribute:
```html
<head>
  <script src="script.js" defer></script>
</head>
```
**Key points:**
- Allows HTML to parse while scripts download
- Scripts execute after full page load

#### Using `async` attribute in `<head>` or `<body>`:
```html
<script src="script.js" async></script>
```
**Key points:**
- Downloads and executes script as soon as possible without blocking parsing

#### For external scripts that need to run immediately:
```html
<script src="external-script.js"></script>
```
**Key points:**
- Place in `<head>` if script is needed for rendering content

### Best Practices
- Use `defer` for scripts that don't rely on DOM elements
- Use `async` for third-party scripts or non-critical functionality
- Place critical JavaScript at the end of `<body>` without `defer`/`async`
- Use modules with `type="module"` for modern, non-blocking loading
- Consider using dynamic script loading for external scripts
- Avoid putting JavaScript directly in HTML attributes like `<a>` tags

### Summary
The best placement depends on your specific needs, but generally:
- Critical scripts go at the bottom of `<body>`
- Non-critical scripts use `defer` or `async`
- External scripts may need to load earlier

Using these techniques can improve page load performance and user experience by allowing content to render faster while still loading necessary scripts.