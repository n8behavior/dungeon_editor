# Dungeon Editor

Let's make sure we're using Python3, and get get our system toolchain ready

```sh
sudo apt install python3 python3-dev python3-venv python-is-python3 python-dev-is-python3 libclang-dev 
```

Then install Qt
https://www.qt.io/download

Virtual env setup
```
python -m venv dungeon_editor_env
source dungeon_editor_env/bin/activate
pip install PySide2 sphinx numpy PyOpenGL
```

Clone this repo

```sh
git clone git@github.com:n8behavior/dungeon_editor
```

Run it

```sh
cd dungeon_editor
python3 dungeon_editor.py
```
