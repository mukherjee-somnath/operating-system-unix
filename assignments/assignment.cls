\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{assignment}[2026 Assignment Class]

\LoadClass[12pt,a4paper]{article}

% ----------- Packages -----------
\RequirePackage[margin=1in]{geometry}
\RequirePackage{titlesec}
\RequirePackage{longtable}
\RequirePackage{enumitem}
\RequirePackage{fancyhdr}
\RequirePackage{xcolor}
\RequirePackage{verbatim}

% ----------- Typography -----------
\setlength{\parindent}{0pt}
\setlength{\parskip}{6pt}
\linespread{1.25}

\titlespacing*{\section}{0pt}{12pt}{6pt}

\titleformat{\section}
{\large\bfseries}
{}
{0pt}
{}

% ----------- Colors -----------
\definecolor{primary}{HTML}{111827}
\definecolor{grayline}{HTML}{9CA3AF}
\definecolor{accent}{HTML}{3B82F6}

% ----------- Dynamic Variables -----------
\newcommand{\assignmentname}{A1: Array}
\newcommand{\authorname}{Somnath Mukherjee, Asst. Prof., MCA}

% ----------- Header & Footer -----------
\pagestyle{fancy}
\fancyhf{}

\fancyfoot[L]{\small \assignmentname}
\fancyfoot[C]{\small \authorname}
\fancyfoot[R]{\small \thepage}

\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0.5pt}

\renewcommand{\footrule}{%
	\vspace{-4pt}
	\hbox to\textwidth{\color{grayline}\leaders\hrule height 0.5pt\hfill}
	\vspace{4pt}
}

% ----------- Divider -----------
\newcommand{\divider}{%
	\par\nointerlineskip\vspace{0.5ex}%
	{\color{grayline}\rule{\linewidth}{0.7pt}}%
	\par\nointerlineskip\vspace{0.5ex}%
}

% ----------- Title Command -----------
\newcommand{\assignmenttitle}[2]{%
	\begin{center}
		{\LARGE\bfseries #1}
		
		\vspace{3pt}
		
		{\large\textbf{#2}}
	\end{center}
	
	\divider
}

% ----------- Lists -----------
\setlist[itemize]{itemsep=2pt, topsep=6pt, parsep=2pt}
\setlist[enumerate]{itemsep=2pt, topsep=6pt, parsep=2pt}