[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("app");

let make = _children => {
  ...component,
  render: _self =>
    <div className="wrapper">
      <h1> (ReasonReact.string("Colors")) </h1>
      <div className="colors">
        <div className="row">
          <div className="item">
            <div className="swatch bg-primary" />
            <h3 className="colorName text-primary">
              (ReasonReact.string("Primary"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-secondary" />
            <h3 className="colorName text-secondary">
              (ReasonReact.string("Secondary"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-accent" />
            <h3 className="colorName text-accent">
              (ReasonReact.string("Accent"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-accent2" />
            <h3 className="colorName text-accent2">
              (ReasonReact.string("Accent 2"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-default" />
            <h3 className="colorName text-default">
              (ReasonReact.string("Default"))
            </h3>
          </div>
        </div>
        <div className="row">
          <div className="item">
            <div className="swatch bg-info" />
            <h3 className="colorName text-info">
              (ReasonReact.string("Info"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-danger" />
            <h3 className="colorName text-danger">
              (ReasonReact.string("Danger"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-warning" />
            <h3 className="colorName text-warning">
              (ReasonReact.string("Warning"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-success" />
            <h3 className="colorName text-success">
              (ReasonReact.string("Success"))
            </h3>
          </div>
          <div className="item">
            <div className="swatch bg-disabled" />
            <h3 className="colorName text-disabled">
              (ReasonReact.string("Disabled"))
            </h3>
          </div>
        </div>
      </div>
      <h1 className="typoHeading"> (ReasonReact.string("Typography")) </h1>
      <div className="typoItems">
        <h2> (ReasonReact.string("Text Colors")) </h2>
        <hr />
        <ul>
          <li className="text-primary text-lg">
            (ReasonReact.string("Primary"))
          </li>
          <li className="text-secondary text-lg">
            (ReasonReact.string("Secondary"))
          </li>
          <li className="text-accent text-lg">
            (ReasonReact.string("Accent"))
          </li>
          <li className="text-accent2 text-lg">
            (ReasonReact.string("Accent 2"))
          </li>
          <li className="text-default text-lg">
            (ReasonReact.string("Default"))
          </li>
          <li className="text-info text-lg">
            (ReasonReact.string("Info"))
          </li>
          <li className="text-danger text-lg">
            (ReasonReact.string("Danger"))
          </li>
          <li className="text-warning text-lg">
            (ReasonReact.string("Warning"))
          </li>
          <li className="text-success text-lg">
            (ReasonReact.string("Success"))
          </li>
          <li className="text-disabled text-lg">
            (ReasonReact.string("Disabled"))
          </li>
        </ul>
        <h2> (ReasonReact.string("Fonts")) </h2>
        <hr />
        <p className="font-default text-2xl">
          (ReasonReact.string("Default"))
        </p>
        <p className="font-mono text-2xl"> (ReasonReact.string("Mono")) </p>
        <h2> (ReasonReact.string("Font Sizes")) </h2>
        <hr />
        <p className="text-xs"> (ReasonReact.string("Extra Small")) </p>
        <p className="text-sm"> (ReasonReact.string("Small")) </p>
        <p className="text-base"> (ReasonReact.string("Base")) </p>
        <p className="text-lg"> (ReasonReact.string("Large")) </p>
        <p className="text-xl"> (ReasonReact.string("Extra Large")) </p>
        <p className="text-2xl"> (ReasonReact.string("2 x Extra Large")) </p>
        <p className="text-3xl text-success">
          (ReasonReact.string("3 x Extra Large"))
        </p>
        <h2> (ReasonReact.string("Font Weights")) </h2>
        <hr />
        <p className="font-bold text-lg"> (ReasonReact.string("Bold")) </p>
        <p className="font-medium text-lg">
          (ReasonReact.string("Medium"))
        </p>
        <p className="font-normal text-lg">
          (ReasonReact.string("Normal"))
        </p>
      </div>
    </div>,
};
