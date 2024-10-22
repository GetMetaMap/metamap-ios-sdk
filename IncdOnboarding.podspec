Pod::Spec.new do |spec|

  spec.name         = "IncdOnboarding"
  spec.version      = "5.30.1-d-l"
  spec.summary      = "IncdOnboarding SDK"
  spec.homepage     = "https://github.com/IncodeTechnologies/"
  spec.license      = { :type => "CDDL-1.0", :text => <<-LICENSE
      Copyright (c) 2018, Incode
      All rights reserved.
      
      THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS"" AND ANY
      EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
      WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
      DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
      DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
      (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
      SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
      CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
      LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
      OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
      DAMAGE.
      LICENSE
  }


  spec.author          = { "Marko Čančar" => "marko.cancar@incode.com" }
  spec.platform        = :ios
  spec.source          = { :path => "." }
  spec.vendored_frameworks = 'IncdOnboarding.xcframework'
  spec.libraries = 'c++'
  spec.swift_version = "5.7"
  spec.ios.deployment_target  = '13.0'
end
