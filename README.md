# Sketch SSOT


The intuit of this project is to bring designers into the codebase development workflow using Invision Studio, by aligning the design tasks with the development repository.

## Goals

High level goals include:

- Using design files as single source of truth for design variables (tokens) and releasing developers from the responsibility of continuously asking for this information from the design team;

- Control/update css variables from design files and automatically update the project's css files;

- Control/update typography variables from sketch and automatically update the project's css files;

- Control/update simple (dumb) components react components with styles;

- Would allow the design team to contribute some code to the project;

- Would allow the design team to create basic building block components for a UI-Kit;

# Running

Currently the workflow is still very much in progress and requires [kactus](https://kactus.io/), [yarn](https://yarnpkg.com/en/), and [nodejs](https://nodejs.org/en/).

## Basic Instructions

In your terminal run

* `git clone git@github.com:mpaiva/sketch-ssot.git`
* `cd sketch-ssot`
* `yarn install`
* `yarn build`
* `yarn exe` - Creates output files

That last command runs the [reasonml](https://reasonml.github.io/) code and generates a css variables file from the sketch data.

Now open the project with kactus and generate/open a sketch file from `variables` in the design folder. At this point you can change the color names and hex values of the color palletes. Save and commit through kactus, then return to the terminal and run `yarn exe` again. The css file in `output/css-next.css` will contain the updated names and values you have changed.

# So far

At this point we only have color variables working. We would like to be able to export to multiple variable styles beyond CSS4 such as SASS to accommodate variations in technical decisions. Typography variables and autogenerating simple react components are next on the roadmap.

# Roadmap

  - Create a proof-of-concept leveraging an existing design system;
  - Clone design system repository;
  - Produce Sketch source file(s)
  - Apply yarn scripts to create output files (SASS), then compile CSS files accordingly
  - Test by reviewing changes on HTML after push.


## Swarm Design System (by meetup.com)

Recommend using the [Swarm Design System](https://meetup.github.io/swarm-design-system/design/color), which contains React, SASS, Storybook, i18n, a11y, and more.

### Design Documentation
- https://meetup.github.io/swarm-design-system/design/color

### Github Repository
- https://github.com/meetup/swarm-design-system
