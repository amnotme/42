# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    react_init.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 12:13:04 by lhernand          #+#    #+#              #
#    Updated: 2018/05/14 13:20:46 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This will get your react.js project up and running.  Use it as is
# Cd into your project and run ->

echo "\033[1;32mCreating your project!\033[0m"
npm init --yes

# Then install the necessary packages

echo "\033[1;32mInstalling packages and dependencies!\033[0m"
npm install --save webpack \
	react \
	react-dom \
	babel-core \
	babel-loader \
	babel-preset-env \
	babel-preset-react \
	webpack-cli

# Configuring your webpack!
echo "\033[1;32mConfiguring your webpack!\033[0m"

echo "const path = require('path');" >> webpack.config.js
echo "" >> webpack.config.js
echo "module.exports = {" >> webpack.config.js
echo "	context: __dirname," >> webpack.config.js
echo "	entry: \"./index.jsx\"," >> webpack.config.js
echo "	output: {" >> webpack.config.js
echo "		path: path.resolve(__dirname)," >> webpack.config.js
echo "		filename: \"bundle.js\"" >> webpack.config.js
echo "}," >> webpack.config.js
echo "module: {" >> webpack.config.js
echo "	rules: [" >> webpack.config.js
echo "		{" >> webpack.config.js
echo "			test: /\\.jsx\?\$/," >> webpack.config.js
echo "			exclude: /(node_modules)/," >> webpack.config.js
echo "			use: {" >> webpack.config.js
echo "				loader: 'babel-loader', " >> webpack.config.js
echo "				query: {" >> webpack.config.js
echo " 					presets: ['env', 'react']" >> webpack.config.js
echo "				}" >> webpack.config.js
echo "			}," >> webpack.config.js
echo "		}" >> webpack.config.js
echo "	]" >> webpack.config.js
echo "}," >> webpack.config.js
echo "devtool: 'source-map'," >> webpack.config.js
echo "resolve: {" >> webpack.config.js
echo "	extensions: [\".js\", \".jsx\", \"\*\"]" >> webpack.config.js
echo "	}" >> webpack.config.js
echo "};" >> webpack.config.js

# Creating test files
echo "\033[1;32mCreating entry file \"index.jsx\"\033[0m"
echo "import React from 'react';" >> index.jsx
echo "import ReactDOM from 'react-dom';" >> index.jsx
echo "import Congrats from './congrats';" >> index.jsx
echo "" >> index.jsx
echo "document.addEventListener(\"DOMContentLoaded\", () => {" >> index.jsx
echo "		const root = document.getElementById(\"root\");" >> index.jsx
echo "		ReactDOM.render(<Congrats/>, root);" >> index.jsx
echo "});" >> index.jsx

echo "\033[1;32mCreating test component \"congrats.jsx\"\033[0m"
echo "import React from 'react';" >> congrats.jsx
echo "" >> congrats.jsx
echo "const Congrats = () => <h1>Congratulations you did it</h1>;" >> congrats.jsx
echo "" >> congrats.jsx
echo "export default Congrats;" >> congrats.jsx

echo "\033[1;32mCreating the \"index.html\"\033[0m"
echo "<!DOCTYPE html>" >> index.html
echo "<html>" >> index.html
echo "<head>" >> index.html
echo "		<title>totes</title>" >> index.html
echo "		<script src=\"bundle.js\"></script>" >> index.html
echo "</head>" >> index.html
echo "<body>" >> index.html
echo "		<div id='root'/>" >> index.html
echo "</body>" >> index.html
echo "</html>" >> index.html


# Be sure to create a git ignore
echo "\033[1;32mCreate your .ignore\033[0m"

# Once the package.json has been generated ->
echo "\033[1;32mAdd a webpack script for webpack to your package.json (\"webpack\": \"webpack --mode=development --watch\")\033[0m"

# You can finally run it
echo "\033[1:32mYou can run your project with 'npm run webpack'\033[0m"
