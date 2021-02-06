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


def download_video(id):
    os.system(
        f'youtube-dl -x --audio-format mp3 https://www.youtube.com/watch?v={id}')


os.chdir("/Volumes/Macbook Files")

with concurrent.futures.ThreadPoolExecutor() as executor:
    executor.map(download_video, vid_ids)
