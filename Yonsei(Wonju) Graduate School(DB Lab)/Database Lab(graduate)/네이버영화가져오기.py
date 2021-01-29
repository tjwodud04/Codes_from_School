from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen("https://movie.naver.com/movie/search/result.nhn?section=movie&query=video")
bs = BeautifulSoup(html, "html.parser")

titlelist = []
for lists in bs.select('dt'):
    # lists.text
    titlelist.append(lists.text)

print(titlelist)  # 리스트
print("---")

for movielist in titlelist:
    print(movielist)  # 변수

'''
네이버 무비의 '마녀' 검색 결과 1페이지에 해당하는 제목을 가져왔습니다.
'''