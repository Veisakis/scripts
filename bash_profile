# Setting PATH for Python 3.8
# The original version is saved in .bash_profile.pysave
export PATH="/Library/Frameworks/Python.framework/Versions/3.8/bin:${PATH}"

if [ -f ~/.bashrc ]; then
	source ~/.bashrc
fi

export GOV_API='cae197251734baf5d81483596ac52d81cb41b779 '
export GEO_API='611cdeb43345c63ff4e45a8711439508'
export YT_API='AIzaSyBrNYJK7eAzbZDBKADgyt19CRGb6Xsdmoo'
export GIT_TKN='36347e66e0fcc2929b6868907b71432944ed8d61'

alias dt='cd ~/Desktop/'
alias ll='ls -al'
alias pt='python3'
alias ipt='ipython'
alias clean='rm -rf /Users/Manousos/Downloads/* && rm -rf /Users/Manousos/.Trash/*'
alias ssdumnt="diskutil unmount /dev/disk2s2 ; diskutil unmount /dev/disk2s3 ; diskutil unmount /dev/disk2s4"
alias yt='youtube-dl -x --audio-format mp3'
alias up='brew update && brew upgrade && brew cleanup'
alias R='/Library/Frameworks/R.framework/Resources/bin/R'
