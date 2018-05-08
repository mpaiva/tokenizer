[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div className="wrapper">
      <h1> (ReasonReact.string("Colors")) </h1>
      <div className="colors">
        <div className="row">
          <div className="item">
            <div className="swatch bg-primary" />
            <h3 className="colorName"> (ReasonReact.string("Primary")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-secondary" />
            <h3 className="colorName"> (ReasonReact.string("Secondary")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-accent" />
            <h3 className="colorName"> (ReasonReact.string("Accent")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-accent2" />
            <h3 className="colorName"> (ReasonReact.string("Accent 2")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-default" />
            <h3 className="colorName"> (ReasonReact.string("Default")) </h3>
          </div>
        </div>
        <div className="row">
          <div className="item">
            <div className="swatch bg-info" />
            <h3 className="colorName"> (ReasonReact.string("Info")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-danger" />
            <h3 className="colorName"> (ReasonReact.string("Danger")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-warning" />
            <h3 className="colorName"> (ReasonReact.string("Warning")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-success" />
            <h3 className="colorName"> (ReasonReact.string("Success")) </h3>
          </div>
          <div className="item">
            <div className="swatch bg-disabled" />
            <h3 className="colorName"> (ReasonReact.string("Disabled")) </h3>
          </div>
        </div>
      </div>
      <h1> (ReasonReact.string("Typography")) </h1>
    </div>,
};