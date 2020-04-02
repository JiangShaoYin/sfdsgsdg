#!/bin/sh

echo "git Synchronizing begin !"

while((1))
do
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : begin to pull"
    git pull origin master &> /dev/null
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : git pull has done!, begin to push"
    git add . && git commit -m "1" && git push origin master &> /dev/null
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : git push has done!"
    echo -e "[${cur_time}] : begin to sleep"
    sleep 20s
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : sleeping 20s........................"
    sleep 20s
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : sleeping 40s........................"
    sleep 20s
    cur_time=$(date +"%T")
    echo -e "[${cur_time}] : sleeping 60s........................\n\n"
done
echo "git Synchronizing end !"


