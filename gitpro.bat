ECHO OFF

echo Welcome, sire.

pause

echo Adding files to working tree...
echo Making commit changes to local repository...
echo Syncing file updates with remote tree...

git add .
git commit -m"cp grind"
git push

echo DONE! What a load of work... Well, see ya next time.

pause