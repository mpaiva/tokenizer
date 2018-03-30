type color = {
  name: string,
  hex: string
};

type colors = list(color);

let colorsDir = "design/variables/--colors";

let clrs =
  colorsDir
  |> Node.Fs.readdirSync
  |> Array.to_list
  |> List.filter(file => file !== "page.json")
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
                     Json.Decode.array(field("value", string))
                   )
              ),
         hex:
           1
           |> Array.get(
                json
                |> field(
                     "overrideValues",
                     Json.Decode.array(field("value", string))
                   )
              )
       }
     );

let rec buildCssVarsAux = (acc: string) =>
  fun
  | [] => acc
  | [{name, hex}, ...list] =>
    list |> buildCssVarsAux(acc ++ "  --" ++ name ++ ": #" ++ hex ++ "\n");

let buildCssVars = (vars: colors) => buildCssVarsAux("", vars);

let output = ":root {\n" ++ buildCssVars(clrs) ++ "}";

Node.Fs.writeFileAsUtf8Sync("output/css-next.css", output);