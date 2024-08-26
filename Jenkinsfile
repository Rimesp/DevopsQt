pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                echo 'Checking out code from GitHub'
                git 'https://github.com/Rimesp/DevopsQt.git'
            }
        }
        stage('Build') {
            steps {
                script {
                    // Print the current directory for debugging
                    bat 'echo Current directory: %CD%'
                    bat 'echo Workspace directory: %WORKSPACE%'

                    // Set up Visual Studio environment and build
                    bat '''
                    "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
                    echo Checking for cl.exe
                    where cl
                    echo Running qmake
                    "C:\\Qt\\5.15.2\\msvc2019_64\\bin\\qmake.exe" QtDev.pro
                    echo Running nmake
                    nmake
                    '''
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Running simplified test...'
            }
        }
            stage('Deploy to Local Machine') {
            steps {
                sshagent(['my-ssh-key']) { // Use the ID of the SSH credential
                    script {
                        // Define paths
                        def localPath = 'C:/Users/rimouertani/DeployedApp/'
                        def remoteFilePath = 'C:/Users/rim/Documents/QtDev/DevopsQt/build/Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/debug/QtDev.exe'
                        
                        // Debugging output
                        bat 'echo Checking if id_rsa exists...'
                        bat 'dir C:/Users/rimouertani/.ssh/id_rsa'
                        
                        bat """
                        echo Deploying to local machine...
                        scp -i C:/Users/rimouertani/.ssh/id_rsa rim@40.127.8.223:"${remoteFilePath}" "${localPath}"
                        """
                    }
                }
            }
        }
    }
    post {
        always {
            echo 'Archiving build artifacts'
            archiveArtifacts artifacts: '**/build/Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/debug/*.exe', allowEmptyArchive: false
            echo 'Performing cleanup'
            // Add cleanup commands if necessary
        }
    }
}
