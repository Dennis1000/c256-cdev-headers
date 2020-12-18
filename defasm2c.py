# Read def.asm file and convert it to a c.h file
# v1.0.4

import sys
import ntpath

filename = sys.argv[2].replace('"','')
outputPath = sys.argv[1].replace('"','')

with open(filename+'.asm') as file_in:
    lines = []
    for line in file_in:
         # move comments into a separate var
         split = line.split(';')
         line = split[0]
         if len(split) > 1:
             comments = ''
             i = 1
             while i < len(split):
                 comments = comments + '//' + split[i]
                 i += 1
         else:
             comments = ''

         # check for a definition
         defsL = line.split('=')
         
         # if there's a $ then "convert" to c-hex
         if len(defsL) >1:
             defs = defsL[1].split('$')

             if len(defs) > 1:
                 addr = defs[1].rstrip();
    
                 # check length of address - it could be a simple const or an address
                 if len(addr)>=6:
                     # treat defines ending with _PTR as arrays
                     if defsL[0].find('_PTR ') != -1:
                       resultLine = '#define ' + defsL[0] + defs[0] + '((volatile unsigned char *)0x' + addr + ')'
                     else:
                       resultLine = '#define ' + defsL[0] + defs[0] + '(*(volatile unsigned char *)0x' + addr + ')'
                 else:
                     resultLine = '#define ' + defsL[0] + defs[0] + '0x' + addr
             else:
                 # without a $ treat as an equation
                 resultLine = '#define ' + line
         else: 
             # comment .byte and .word definitions
             if (line.find('.byte') != -1) or (line.find('.word') != -1):
                 resultLine = '//' + line
             else:
                 # check for .include
                 if line.find('.include ') != -1:
                     line = line.replace(".include", "#include")
                     line = line.replace(".asm", ".h")
                     resultLine = line
                 else:
                     resultLine = line

         resultLine = resultLine + '  ' + comments if len(resultLine) > 0 else comments
         lines.append(resultLine.rstrip() + '\n')

# writing to file 
file1 = open(outputPath + '\\' + ntpath.basename(filename) + '.h', 'w') 
file1.writelines(lines) 
file1.close() 
