# React

React is a JavaScript library for building user interfaces. It is maintained by Facebook and a community of individual developers and companies. React can be used as a base in the development of single-page or mobile applications. It is a component-based library which is used to develop interactive UIs (User Interfaces).

## Resources

- [React - Learn](https://react.dev/learn)
- [W3schools - React](https://www.w3schools.com/react/default.asp)

## How does React work?

React creates a virtual DOM. When state changes in a component it firstly runs a "diffing" algorithm, which identifies what has changed in the virtual DOM. The second step is reconciliation, where it updates the DOM with the results of diff.

React update only what's necessary.

## Components

Components are the building blocks of any React application, and a single app usually consists of multiple components. A component is a JavaScript class or function that optionally accepts inputs i.e. properties(props) and returns a React element that describes how a section of the UI (User Interface) should appear.

## State

State is a built-in React object that contains data that influences the output of render. The state of a component can change over time in response to user actions, network responses, and anything else that causes the data displayed in the UI to change.

State is **mutable**, and it is typically used to store property values that belong to a component. When the state of a component changes, the component is **re-rendered**. The state of a component can be changed by calling the `setState` method.

```jsx
import useState from "react";

function App() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>Click me</button>
    </div>
  );
}
```

### Managing state

Instead of create complex props drilling:
![react props drilling schema](https://react.dev/_next/image?url=%2Fimages%2Fdocs%2Fdiagrams%2Fpassing_data_prop_drilling.png&w=640&q=75)

Using Context allow to store data in all children of a tree, instead of adding the data to props everytime (error prone).
![react context pass schema](https://react.dev/_next/image?url=%2Fimages%2Fdocs%2Fdiagrams%2Fpassing_data_context_far.png&w=640&q=75)


