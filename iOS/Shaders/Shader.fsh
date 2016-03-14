//
//  Shader.fsh
//  Anura
//
//  Created by Ben Anderman on 3/10/16.
//  Copyright © 2016 Ben Anderman. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
