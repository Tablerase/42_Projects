# Querying

## [What is querying?](https://www.techtarget.com/searchdatamanagement/definition/query)

Querying is a way to ask a question to the database. The database will return the data that matches the question.

Quierying can be done in different ways, depending on the database and the language used to interact with it.

```mermaid
graph LR
  classDef primary fill:#cba6f7,stroke:#6c7086,stroke-width:2px;
  classDef secondary fill:#f9e2af,stroke:#9399b2,stroke-width:2px;
  classDef text fill:#cdd6f4,stroke:#333,stroke-width:2px;
  classDef subtext fill:#bac2de,stroke:#333,stroke-width:2px;
    A[User]:::primary -->|Sends Query| B[Application]:::secondary
    B -->|Processes Query| C[Database]:::primary
    C -->|Returns Data| B
    B -->|Displays Data| A
```

## Querying in Web Development

In web development, querying is often done using AJAX. AJAX is a set of web development techniques that allows web pages to be updated asynchronously by exchanging data with a web server behind the scenes. This means that it is possible to update parts of a web page without reloading the entire page.

Other ways to query data in web development include using a database query language like SQL or using a web development framework like Django or Ruby on Rails.

### [AJAX](https://www.ibm.com/docs/en/rational-soft-arch/9.7.0?topic=page-asynchronous-javascript-xml-ajax-overview)

AJAX stands for Asynchronous JavaScript and XML. It is a set of web development techniques that allows web pages to be updated asynchronously by exchanging data with a web server behind the scenes. This means that it is possible to update parts of a web page without reloading the entire page.

```mermaid
graph LR
  classDef primary fill:#cba6f7,stroke:#6c7086,stroke-width:2px;
  classDef secondary fill:#f9e2af,stroke:#9399b2,stroke-width:2px;
  classDef text fill:#cdd6f4,stroke:#333,stroke-width:2px;
  classDef subtext fill:#bac2de,stroke:#333,stroke-width:2px;
    A[User]:::primary -->|Clicks Button| B[JavaScript]:::secondary
    B -->|Sends AJAX Request| C[Server]:::primary
    C -->|Processes Request| B
    B -->|Updates Page| A
```

### JQUERY

jQuery is a fast, small, and feature-rich JavaScript library. It makes things like HTML document traversal and manipulation, event handling, and animation much simpler with an easy-to-use API that works across a multitude of browsers. With a combination of versatility and extensibility, jQuery has changed the way that millions of people write JavaScript. jQuery is often used to make AJAX requests in web development.

Here is an example of how to use jQuery to make an AJAX request:

```javascript
$.ajax({
  url: 'https://api.example.com/data',
  method: 'GET',
  success: function(data) {
    console.log(data);
  },
  error: function(xhr, status, error) {
    console.error(error);
  }
});
```

