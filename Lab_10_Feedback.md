### Feedback for Lab 10

Run on March 02, 08:16:40 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		328bd24ccf76443bb136e558ba9c1ff4cedb1020	refs/heads/devel

		dc6a7435a1d73fd06ddae862efc5e64b6810e425	refs/heads/fix/01-compilation-errors

		ca0e3b7b47a5d8758c8f70f41e3b311738fc241a	refs/heads/fix/02-google-style-errors

		9a0a3bf418cbc1e033d3345f348509c8866672ab	refs/heads/master

		47c5c85335549d27019fbee3ea2666a3ca21e86d	refs/heads/support-code



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-google-style-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[/Chenxuan] 2020-03-01 (HEAD -> devel, origin/devel) Merge branch 'fix/02-google-style-errors' into devel 

		[/Chenxuan] 2020-03-01 (origin/fix/02-google-style-errors, fix/02-google-style-errors) fix google style errors 

		[/Chenxuan] 2020-03-01 Merge branch 'fix/02-google-style-errors' into devel 

		[/Chenxuan] 2020-03-01 fix to make cpplint run 

		[/Chenxuan] 2020-02-29 run feedback 

		[/Chenxuan] 2020-02-29 Merge branch 'fix/01-compilation-errors' into devel 

		[/Chenxuan] 2020-02-29 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix bug 

		[/Chenxuan] 2020-02-28 copy src directory from lab10 

		[/Chenxuan] 2020-02-28 delete src directory 


		[/Chenxuan] 2020-02-28 runfeedback 

		[/Chenxuan] 2020-02-28 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-liu00464 

		[/Chenxuan] 2020-02-28 lab9 push1 


		[/Chenxuan] 2020-02-28 fix multiply files 

		[/Chenxuan] 2020-02-28 update 


		[Chenxuan Liu] 2020-02-27 update 

		[Chenxuan Liu] 2020-02-27 lab9and10feedback 

		[Chenxuan Liu] 2020-02-27 update ds_store 



		[Chenxuan Liu] 2020-02-27 update 

		[Chenxuan Liu] 2020-02-27 iteration1 
































		[Chenxuan Liu] 2020-02-23 update 

		[Chenxuan Liu] 2020-02-23 update 

		[Chenxuan Liu] 2020-02-23 update 

		[Chenxuan Liu] 2020-02-23 Update 






















		[Chenxuan Liu] 2020-02-22 Update 

		[Chenxuan Liu] 2020-02-22 change 

		[Chenxuan Liu] 2020-02-22 fix 



		[Chenxuan Liu] 2020-02-22 update 

		[Chenxuan Liu] 2020-02-22 update 


		[Chenxuan Liu] 2020-02-22 update 


		[Chenxuan Liu] 2020-02-22 update 

		[Chenxuan Liu] 2020-02-22 update 


		[Chenxuan Liu] 2020-02-22 Lab08 Update 




















		[/Chenxuan] 2020-02-21 complete version 



		[/Chenxuan] 2020-02-21 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-liu00464 

		[/Chenxuan] 2020-02-21 uncomplete 

		[/Chenxuan] 2020-02-21 Merge branch 'support-code' 

		[/Chenxuan] 2020-02-21 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 


























+ Pass: Check git commit history
Sufficient commits (found=37,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 2)

[OPEN issue #2] :  Google style error [enhancement]

[OPEN issue #1] :  simulator_does_not_compile [bug]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #2] :  Google style error [enhancement]

[OPEN issue #1] :  simulator_does_not_compile [bug]

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+ Pass: Check that file "makefile" exists.

+ Pass: Check that make compiles.



