type color = {
  name: string,
  hex: string,
};

type typo = {
  name: string,
  value: string,
};

type variableSet =
  | Colors(list(color))
  | Typography(list(typo));

let rec buildColorCssVars = (acc: string) =>
  fun
  | [] => acc
  | [{name, hex}, ...list] =>
    list |> buildColorCssVars(acc ++ "  --" ++ name ++ ": #" ++ hex ++ ";\n");

let rec buildTypoCssVars = (acc: string) =>
  fun
  | [] => acc
  | [{name, value}, ...list] =>
    list |> buildTypoCssVars(acc ++ "  --" ++ name ++ ": " ++ value ++ ";\n");

let buildCssVars =
  fun
  | Colors(clrs) => buildColorCssVars("", clrs)
  | Typography(typs) => buildTypoCssVars("", typs);

let buildColors = colorsDir => {
  Js.log("Building Color Variables!");
  Js.log("Reading data from " ++ colorsDir);
  let clrs =
    colorsDir
    |> Node.Fs.readdirSync
    |> Array.to_list
    |> List.filter(file =>
         file !== "page.json" && Js.String.includes(".json", file)
       )
    |> List.map(file => Node.Fs.readFileAsUtf8Sync(colorsDir ++ "/" ++ file))
    |> List.map(Json.parseOrRaise)
    |> List.map(json =>
         Json.Decode.{
           name:
             0
             |> Array.get(
                  json
                  |> field(
                       "overrideValues",
                       Json.Decode.array(field("value", string)),
                     ),
                ),
           hex:
             1
             |> Array.get(
                  json
                  |> field(
                       "overrideValues",
                       Json.Decode.array(field("value", string)),
                     ),
                ),
         }
       );
  Colors(clrs);
};

let buildTypography = typographyDir => {
  Js.log("Building Typography Variables");
  Js.log("Reading data from " ++ typographyDir);
  let typos =
    typographyDir
    |> Node.Fs.readdirSync
    |> Array.to_list
    |> List.filter(file => file !== "page.json")
    |> List.hd
    |> (
      dir =>
        Node.Fs.readdirSync(typographyDir ++ "/" ++ dir)
        |> Array.to_list
        |> List.filter(file => file !== "artboard.json")
        |> List.map(file =>
             Node.Fs.readFileAsUtf8Sync(
               typographyDir ++ "/" ++ dir ++ "/" ++ file,
             )
           )
        |> List.map(Json.parseOrRaise)
        |> List.map(json =>
             Json.Decode.{
               name:
                 0
                 |> Array.get(
                      json
                      |> field(
                           "overrideValues",
                           Json.Decode.array(field("value", string)),
                         ),
                    ),
               value:
                 1
                 |> Array.get(
                      json
                      |> field(
                           "overrideValues",
                           Json.Decode.array(field("value", string)),
                         ),
                    ),
             }
           )
    );
  Typography(typos);
};

let buildVars = () => {
  let colorVars = buildColors("design/variables/--colors");
  let typoVars = buildTypography("design/swarm_design_tokens/typography");
  ":root {\n" ++ buildCssVars(colorVars) ++ buildCssVars(typoVars) ++ "}";
};

let run = () => {
  let variables = buildVars();
  Node.Fs.writeFileAsUtf8Sync("demo/src/style/variables.css", variables);
  ();
};

run();

[%bs.raw
  {|
    Fs.watch("design", { encoding: 'buffer' }, function() {
      run();
    })
  |}
];