from setuptools import setup, find_packages


setup(
    name="torchph",
    version="0.1.0",
    author="Sayantan Das",
    author_email="sayantandas30011998@gmail.com",
    description="torchph",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/forkbabu/torchph",
    packages=setuptools.find_packages(exclude=('tests*',)),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
    keywords='Persistent Homology',
)
