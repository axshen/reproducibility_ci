# Reproducibility CI

# Travis CI Badges

[![Build Status](https://travis-ci.com/axshen/reproducibility_ci.svg?branch=main)](https://travis-ci.com/axshen/reproducibility_ci)

# Github Action Badges

[![Build Status](https://github.com/axshen/reproducibility_ci/workflows/Linting/badge.svg)](https://github.com/axshen/reproducibility_ci/actions)

A repository with CI scripts for code reproducibility including:

- linting (python with [pep8](https://pep8.org/), c/c++ with [google styleguide](https://google.github.io/styleguide/cppguide.html))

## Static linting

* [pycodestyle](https://github.com/PyCQA/pycodestyle) for pip installable library to perform static pep8 checks on your code. This should be run prior to the creation of pull requests.
* [cpplint](https://github.com/cpplint/cpplint) for c++ static linting.
