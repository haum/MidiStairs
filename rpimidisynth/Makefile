all:
	echo 'Only "install" target is available here'

install:
	sudo mkdir -p /etc/rpimidisynth/
	sudo cp fluidsynth.conf /etc/rpimidisynth/
	sudo cp rpimidisynth /usr/local/bin/
	sudo cp rpimidisynth.service /lib/systemd/system/
	sudo systemctl enable rpimidisynth
	sudo cp rpimidiautoconnect /usr/local/bin/
	sudo cp rpimidiautoconnect.service /lib/systemd/system/
	sudo systemctl enable rpimidiautoconnect
