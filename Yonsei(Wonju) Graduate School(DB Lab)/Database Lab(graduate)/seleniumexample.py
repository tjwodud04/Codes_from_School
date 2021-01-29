from selenium import webdriver
from bs4 import BeautifulSoup
import time

driver = webdriver.Chrome('/Users/j/Desktop/chromedriver')
#driver = webdriver.PhantomJS('/Users/j/Desktop/phantomjs-2.1.1-windows/bin/phantomjs')
driver.implicitly_wait(3)
driver.get('https://www.bigkinds.or.kr/main.do')
driver.find_element_by_name('searchTxt').send_keys('게임')
driver.find_element_by_xpath("//button[@class='searchBtn']").click()

#driver.get('https://www.bigkinds.or.kr/news/newsResult.do')
time.sleep(7)
html = driver.page_source
bs = BeautifulSoup(html, 'html.parser')

titlelist = []
list = bs.find_all('h3', {'class':'list_newsId'})
print([ x.get_text().rstrip() for x in list])


# for lists in list:
#     titlelist.append(lists)
#
# print(titlelist)
