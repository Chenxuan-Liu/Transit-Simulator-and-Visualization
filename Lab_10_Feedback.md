### Feedback for Lab 10

Run on February 29, 16:44:41 PM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		47882f1428d215993aacd80e858a9198e3f4f5b6	refs/heads/devel

		dc6a7435a1d73fd06ddae862efc5e64b6810e425	refs/heads/fix/01-compilation-errors

		0b5ac4e5ec25b8d8320d369fcb4ba2443c4118a5	refs/heads/master

		47c5c85335549d27019fbee3ea2666a3ca21e86d	refs/heads/support-code



+ Pass: Checking for the correct number of branches

Insufficient branches found (found=1, required=2):

fix/01-compilation-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[/Chenxuan] 2020-02-29 (HEAD -> devel, origin/devel) run feedback 

		[/Chenxuan] 2020-02-29 Merge branch 'fix/01-compilation-errors' into devel 

		[/Chenxuan] 2020-02-29 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix bug 

		[/Chenxuan] 2020-02-28 (origin/master, origin/HEAD, master) copy src directory from lab10 

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
Sufficient commits (found=33,required=4)


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



