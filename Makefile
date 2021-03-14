aidsen.hpp: $(wildcard *.patch) 3rd_party/aids.hpp
	rm -f aidsen.hpp
	cp 3rd_party/aids.hpp aidsen.hpp
	git apply aidsen-*.patch

.PHONY: copy
copy: aidsen.hpp
	cp aidsen.hpp aidsen-modified.hpp

.PHONY: patch
patch: aidsen-modified.hpp
	@echo It is assumed that you copied aidsen.hpp to aidsen-modified.hpp
	@echo and you modified the latter one
	rm -f aidsen.hpp
	cp 3rd_party/aids.hpp aidsen.hpp
	git apply aidsen-*.patch
	diff -u aidsen.hpp aidsen-modified.hpp > new.patch || true
	sed -i 's/+++ aidsen-modified.hpp/+++ aidsen.hpp/g' new.patch

.PHONY: tests
tests: aidsen.hpp
	(cd tests && make -j2)

.PHONY: coverage
coverage: aidsen.hpp
	(cd tests && make -j2 coverage)

