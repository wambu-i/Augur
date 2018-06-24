#### Backus Naur Form for the Augur Language

#### Numbers  
numbers = (digit | nonzerodigit | octaldigit | hexdigit | binarydigit | exponential)+  
digit ::= [0-9]  
decimal ::=  
exponential ::= (digit)+(.(digit)+)?(E[+-]?(digit)+)?  
nonzerodigit ::= [1-9]  
octaldigit ::= [0-7]([0-7])*  
hexdigit = [0-9a-fA-F]([0-9a-fA-F])* 
binarydigit = [0-1]([0-1])*  

#### Letters and strings  
letter ::= [A-za-z]  
character ::= '\w'  


#### Whitespace
delimiter ::= '\s'  
ws = (delimeter)+  

### Identifiers
id ::= letter_ (letter_ | digit_ | character)*

#### KeyWords


#### Operations


#### Control statements


#### Comparison
