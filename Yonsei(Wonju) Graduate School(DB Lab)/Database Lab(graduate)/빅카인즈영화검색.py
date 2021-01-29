from urllib.request import urlopen
from bs4 import BeautifulSoup

html=urlopen("https://www.bigkinds.or.kr/news/subMain.do")
bs = BeautifulSoup(html, "html.parser")

print(bs)

titlelist = []
contentlist = []
for lists in bs.find_all('h3', {'id':'pop_newsTitle'}):
    lists.text
    titlelist.append(lists.text)

for listcontents in bs.find_all('div', {'class' : 'doc_desc'}):
    listcontents.text
    contentlist.append(listcontents.text)

print(titlelist)
print(contentlist)