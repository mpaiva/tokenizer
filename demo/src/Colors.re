let component = ReasonReact.statelessComponent("Colors");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <div> (ReasonReact.stringToElement("Hello! " ++ name)) </div>
};