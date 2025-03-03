Turkish FrameNet
============

## FrameNet

Introduced in 1997, FrameNet (Lowe, 1997; Baker et al., 1998; Fillmore and Atkins, 1998; Johnson et al., 2001) has been developed by the International Computer Science Institute in Berkeley, California. It is a growing computational lexicography project that offers in-depth semantic information on English words and 
predicates. Based on the theory of Frame Semantics by Fillmore (Fillmore and others, 1976; Fillmore, 2006), FrameNet offers semantic information on predicate-argument structure in a way that is loosely similar to wordnet (Kilgarriff and Fellbaum, 2000).

In FrameNet, predicates and related lemmas are categorized under frames. The notion of frame here is thoroughly described in Frame Semantics as a schematic representation of an event, state or relationship. These semantic information packets called frames are constituted of individual lemmas (also known as Lexical Units) and frame elements (such as the agent, theme, instrument, duration, manner, direction etc.). Frame elements can be described as semantic roles that are related to the frame. Lexical Units, or lemmas, are linked to a frame through a single sense. For instance, the lemma ”roast” can mean to criticise harshly
or to cook by exposing to dry heat. With its latter meaning, ”roast” belongs to the Apply Heat frame.

## Turkish FrameNet

In this version of Turkish FrameNet, we aimed to release a version of Turkish FrameNet that captures at least a considerable majority of the most frequent predicates, thus offering a valuable and practical resource from day one. Because Turkish is a low-resource language, it was important to ensure that FrameNet had enough coverage that it could be incorporated into NLP solutions as soon as it is released to the public.

We took a closer look at Turkish WordNet and designated 8 domains that would possibly contain the most frequent predicates in Turkish: Activity, Cause, Change, Motion, Cognition, Perception, Judgement and Commerce. For the first phase, the focus was on the thorough annotation of these domains. Frames from
English FrameNet were adopted when possible and new frames were created when needed. In the next phase, team of annotators will attack the
Turkish predicate compilation offered by TRopBank and KeNet for a lemma-by-lemma annotation process. This way, both penetration and coverage of the Turkish FrameNet will be increased.

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/TurkishFrameNet/blob/master/video.jpg" width="50%">](https://youtu.be/mE600WMdSrQ)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/TurkishFrameNet), [Python](https://github.com/starlangsoftware/TurkishFrameNet-Py), [Cython](https://github.com/starlangsoftware/TurkishFrameNet-Cy), [Swift](https://github.com/starlangsoftware/TurkishFrameNet-Swift), [C](https://github.com/starlangsoftware/TurkishFrameNet-C), [Js](https://github.com/starlangsoftware/TurkishFrameNet-Js), [Php](https://github.com/starlangsoftware/TurkishFrameNet-Php), or [C#](https://github.com/starlangsoftware/TurkishFrameNet-CS) repository.

## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called DataStructure will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/TurkishFrameNet-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run TurkishFrameNet-CPP.

Detailed Description
============

+ [FrameNet](#framenet)
+ [Frame](#frame)

## FrameNet

FrameNet'i okumak ve tüm Frameleri hafızada tutmak için

	a = new FrameNet();

Frameleri tek tek gezmek için

	for (int i = 0; i < a.size(); i++){
		Frame frame = a.getFrame(i);
	}

Bir fiile ait olan Frameleri bulmak için

	frames = a.getFrames("TUR10-1234560")

## Frame

Bir framein lexical unitlerini getirmek için

	string getLexicalUnit(int index)
		
Bir framein frame elementlerini getirmek için

	string getFrameElement(int index)

# Cite

	@inproceedings{marsan20,
 	title = {{B}uilding the {T}urkish {F}rame{N}et},
 	year = {2021},
 	author = {B. Marsan and N. Kara and M. Ozcelik and B. N. Arican and N. Cesur and A. Kuzgun and E. Saniyar and O. Kuyrukcu and O. T. Y{\i}ld{\i}z},
 	booktitle = {Proceedings of GWC 2021}
	}
