import os
import re
from datetime import timedelta
from googleapiclient.discovery import build
import concurrent.futures


vid_ids = []
api_key = os.environ['YT_API']

youtube = build('youtube', 'v3', developerKey=api_key)

nextPageToken = None
while True:
    pl_request = youtube.playlistItems().list(
        part='contentDetails',
        playlistId="UUXynnXkWjVqGgZo02vCfl9g",
        maxResults=50,
        pageToken=nextPageToken
    )

    pl_response = pl_request.execute()

    for item in pl_response['items']:
        vid_ids.append(item['contentDetails']['videoId'])

    nextPageToken = pl_response.get('nextPageToken')

    if not nextPageToken:
        break


os.chdir("/Volumes/Macbook Files/rock")


def download_video(id):
    os.system(
        f'youtube-dl -x --audio-format mp3 https://www.youtube.com/watch?v={id}')


backup = []

with open("/Volumes/MacBook Files/rock/backup.txt", "r") as f:
    for vid in f:
        backup.append(vid.strip())

new_vids = list(set(vid_ids).difference(set(backup)))


with open("/Volumes/MacBook Files/rock/backup.txt", "w") as f:
    for vid in vid_ids:
        f.write(vid + "\n")


print(f'There are {len(new_vids)} new Rock Albums available!')


if new_vids:
    proceed = input('Do you want to proceed downloading them? (y/n) ')

    if proceed == 'y' :
        with concurrent.futures.ThreadPoolExecutor() as executor:
            executor.map(download_video, new_vids)

else:
    print('There are no new albums.')
