set shell := ["/bin/sh", "-eu", "-c"]

verify-input:
	python3 tools/godhand.py verify-input

extract: verify-input
	python3 tools/godhand.py extract

analyze: verify-input
	python3 tools/godhand.py analyze

import-ghidra:
	@echo 'UNVERIFIED: Ghidra integration is not configured'

build:
	@echo 'UNVERIFIED: no reconstructed source units exist yet'

lint:
	python3 -m compileall -q tools

compare:
	python3 tools/godhand.py compare

compare-fn address:
	python3 tools/godhand.py compare-fn {{address}}

datacmp:
	python3 tools/godhand.py datacmp

vtable:
	python3 tools/godhand.py vtable

test:
	python3 tools/godhand.py test

report:
	python3 tools/godhand.py report

roadmap:
	python3 tools/godhand.py roadmap

context address:
	python3 tools/godhand.py context {{address}}

check: lint
	python3 tools/godhand.py check
