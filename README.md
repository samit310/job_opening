# Drupal 7 Job Opening

Admin can create Job Opening node, end user can apply for that job if deadline is not crossed also upload only the allowed file format Resume. 

## Getting Started

These instructions will help to integrate the **Job Opening** Module.

### Instructions

Enable the **Job Opening** Module.

### Note

Make sure to download Required module first, mainly **features_extra** module.

```
drush dl features features_extra

drush en job_opening
```

### Job Opening node

```
Fill the Job Details eg. Job Description, DEADLINE TO APPLY {Date}, Points and Allowed resume file format etc, and Save.
```
On the node view page on **Sidebar First** region you will see the **Apply Now** link/button, Click and submit the details. 
**(ONLY if deadline is not crossed.)**

## Job report

### Job Report Link : 
**/job-report**

**Pivot Tables for Views** [https://www.drupal.org/project/views_pivot] module is use for Job report page.

### Note
```
Please apply patch for /views_pivot/views_pivot.theme.inc file, Patch file is inside of Patch Folder.
```

## Authors

* **Samit K** - [Drupal.org](https://www.drupal.org/u/samit310gmailcom)

See also the list of [contributions](https://github.com/samit310)