import pip
from subprocess import call

for i in pip.get_installed_distribuitions():
    call("pip install --upgrade " + i.project_name, shell=True)