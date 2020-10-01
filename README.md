# PKG
All in one package manager.

This is a C wrapper that integrates with the prebuilt package managers in various Operating Systems. The purpose of this wrapper is to enable a easier package management without having to know the flags and options of every package manager.

## How to use

### Install

`sudo make clean install`

### Usage

`pkg <command>`

### Commands

* **c**	*clean* - removes orphans and cleans the package cache

* **h**	*help* - shows help message

* **i**	*install* - installs selected packages

* **q**	*query* - display installed packages

* **r**	*remove* - remove a selected package

* **s**	*search* - look up for a package in the available repositories

* **u**	*update* - updates repos and packages

## Supported OS'es

* Arch Linux based distros;
* Debian based distros;
* Fedora based distros;
* Gentoo based distros;
* OpenSUSE based distros;
* Void Linux *(or xbps)* derived/based distro.

## FAQ

**Q: Will you ever add *X* OS to the wrapper?**

A: Depends on the OS notoriety and usage, unless you open a PR with your code to adding support to the desired OS. In that case, I'll gladly merge the PR.

## Authors:

* Rafael Marçalo
