/** @type {import('tailwindcss').Config} */
const withMT = require("@material-tailwind/react/utils/withMT"); 

module.exports = withMT({ 
  content: [
    "./src/**/*.{js,jsx,ts,tsx}", 
    "path/to/node_modules/@material-tailwind/react/components/**/*.{js,ts,jsx,tsx}", 
    "path/to/node_modules/@material-tailwind/react/theme/components/**/*.{js,ts,jsx,tsx}", 
  ],
  theme: {
    extend: {},
  },
  plugins: [],
});