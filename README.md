# Sketch SSOT

## Goals

* Control/update css variables from sketch and automatically update the project's css files

* Control/update typography variables from sketch and automatically update the project's css files

* Control/update simple (dumb) components react components with styles
  * Would allow the design team to contribute some code to the project
  * Would allow the design team to create basic building block components for a UI-Kit

# Running

Currently the workflow is still very much in progress and requires [kactus](https://kactus.io/), [yarn](https://yarnpkg.com/en/), and [nodejs](https://nodejs.org/en/).

## Basic Instructions

In your terminal run

* `git clone git@github.com:mpaiva/sketch-ssot.git`
* `cd sketch-ssot`
* `yarn install`
* `yarn build`
* `yarn exe`

That last command runs the [reasonml](https://reasonml.github.io/) code and generates a css variables file from the sketch data.

Now open the project with kactus and generate/open a sketch file from `variables` in the design folder. At this point you can change the color names and hex values of the color palletes. Save and commit through kactus, then return to the terminal and run `yarn exe` again. The css file in `output/css-next.css` will contain the updated names and values you have changed.

# So far

At this point we only have color variables working. We would like to be able to export to multiple variable styles beyond css4 such as scss to accomodate variations in technical decisions. Typography variables and autogenerating simple react components are next on the roadmap.
