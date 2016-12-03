#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
map<string,int> sinkron,data;
map<string,int> cek,cek2;
map<string,vector<pair<string,string> > > v,v2;
map<string,int> tot;

int main(){
    vector<string> in,ot,in2,ot2,in3,ot3;
    vector<string> state1,state2;
    string a,d,e,c;
    int b;
    bool bisa=0;
    vector<string> kk;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        if(a=="IN"){
            for(int j=0;j<b;j++){
                cin>>c;
                in.pb(c);
            }
        } else if(a=="OUT"){
            for(int j=0;j<b;j++){
                cin>>c;
                ot.pb(c);
            }
        } else if(a=="TRANSITION"){
            for(int j=0;j<b;j++){
                cin>>d>>e>>c;
                if(cek[d]==0){
                    cek[d]=1;
                    state1.pb(d);
                }
                if(cek[e]==0){
                    cek[e]=1;
                    state1.pb(e);
                }
                v[d].pb(mp(e,c));
                data[c]=1;
            }
        }
    }
    for(int i=0;i<3;i++){
        cin>>a>>b;
        if(a=="IN"){
            for(int j=0;j<b;j++){
                cin>>c;
                in2.pb(c);
            }
        } else if(a=="OUT"){
            for(int j=0;j<b;j++){
                cin>>c;
                ot2.pb(c);
            }
        } else if(a=="TRANSITION"){
            for(int j=0;j<b;j++){
                cin>>d>>e>>c;
                if(cek2[d]==0){
                    cek2[d]=1;
                    state2.pb(d);
                }
                if(cek2[e]==0){
                    cek2[e]=1;
                    state2.pb(e);
                }
                v2[d].pb(mp(e,c));
                if(data[c]==1){
                    bisa=1;
                    sinkron[c]=1;
                }
            }
        }
    }
    if(bisa){
        int l=in.size();
        for(int i=0;i<l;i++){
            if(tot[in[i]]==0){
                tot[in[i]]=1;
                in3.pb(in[i]);
            }
        }
        l=in2.size();
        for(int i=0;i<l;i++){
            if(tot[in2[i]]==0){
                tot[in2[i]]=1;
                in3.pb(in2[i]);
            }
        }
        l=ot.size();
        for(int i=0;i<l;i++){
            if(tot[ot[i]]==0){
                tot[ot[i]]=1;
                ot3.pb(ot[i]);
            }
        }
        l=ot2.size();
        for(int i=0;i<l;i++){
            if(tot[ot2[i]]==0){
                tot[ot2[i]]=1;
                ot3.pb(ot2[i]);
            }
        }
        int jj=in3.size();
        cout<<"IN "<<jj<<"\n";
        for(int i=0;i<jj;i++)cout<<in3[i]<<"\n";
        jj=ot3.size();
        cout<<"OUT "<<jj<<"\n";
        for(int i=0;i<jj;i++)cout<<ot3[i]<<"\n";
        vector<pair<string,pair<string,string> > > transisi;
        int kiri=state1.size();
        int kanan=state2.size();
        for(int i=0;i<kiri;i++){
            for(int j=0;j<kanan;j++){
                string dari,ke;
                int hehe=state1[i].length();
                for(int k=0;k<hehe;k++){
                    dari.pb(state1[i][k]);
                }
                hehe=state2[j].length();
                for(int k=0;k<hehe;k++){
                    dari.pb(state2[j][k]);
                }
                for(int k=0;k<v[state1[i]].size();k++){
                    if(sinkron[v[state1[i]][k].se]==0){
                        for(int l=0;l<v[state1[i]][k].fi.length();l++){
                            ke.pb(v[state1[i]][k].fi[l]);
                        }
                        for(int l=0;l<hehe;l++){
                            ke.pb(state2[j][l]);
                        }
                        transisi.pb(mp(dari,mp(ke,v[state1[i]][k].se)));
                        ke.clear();
                    } else {
                        for(int l=0;l<v2[state2[j]].size();l++){
                            if(v2[state2[j]][l].se==v[state1[i]][k].se){
                                for(int m=0;m<v[state1[i]][k].fi.length();m++){
                                    ke.pb(v[state1[i]][k].fi[m]);
                                }
                                for(int m=0;l<v[state2[j]][l].fi.length();m++){
                                    ke.pb(v[state2[j]][l].fi[m]);
                                }
                                transisi.pb(mp(dari,mp(ke,v[state1[i]][k].se)));
                                ke.clear();
                            }
                        }
                    }
                }
                for(int k=0;k<v[state2[j]].size();k++){
                    if(sinkron[v[state2[j]][k].se]==0){
                        hehe=state1[i].length();
                        for(int l=0;l<hehe;l++){
                            ke.pb(state1[i][l]);
                        }
                        for(int l=0;l<v[state2[j]][k].fi.length();l++){
                            ke.pb(v[state2[j]][k].fi[l]);
                        }
                        transisi.pb(mp(dari,mp(ke,v[state2[j]][k].se)));
                        ke.clear();
                    }
                }
                dari.clear();
            }
        }
        cout<<"TRANSITION\n";
        for(int i=0;i<transisi.size();i++){
            cout<<transisi[i].fi<<' '<<transisi[i].se.fi<<' '<<transisi[i].se.se<<"\n";
        }
    } else cout<<"Not Synchronized\n";
}
