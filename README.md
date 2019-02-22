# Data Structure
## docker build, run 방법

## git branch 관리
 - feature_XXX_featureName 브랜치를 생성하여 작업  
	git checkout -b feature_XXX_featureName
	
 - 수정 및 구현이 완료된 후에는 master branch로 merge  
	git checkout master
	git merge feature_XXX_featureName
	git add -A
	git commit -a
	git push
 